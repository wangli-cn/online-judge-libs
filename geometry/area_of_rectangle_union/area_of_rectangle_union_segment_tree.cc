#include <iostream>
#include <vector>
#include <complex>
#include <memory>
#include <algorithm>
#include <list>

using Point = std::complex<int>;
using Polygon = std::vector<Point>;

#define REP(i, n) for(int i = 0; i < (int)n; ++i)

namespace std {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

};

class Rectangle: public std::vector<Point>
{
public:
    Rectangle() = delete;
    explicit Rectangle(const Point a, const Point b) {
        push_back(a);
        push_back(b);
    }
};


using Position = int;

class Interval
{
public:
    Position low, high;

    Interval() = delete;
    explicit Interval(Position low, Position high)
      :low(low), high(high) {}
};


class SegmentTree
{
public:
    std::vector<Position> pos;

    class Node {
    public:
        int cnt;
        int regions_len;
        Position B, M, E;

    private:
        std::unique_ptr<Node> left, right;

        friend class SegmentTree;
    };

    std::unique_ptr<Node> root;

    explicit SegmentTree(std::vector<Position> pos): pos(std::move(pos)) {
        root = build_tree(0, this->pos.size()-1);
    }
    ~SegmentTree() {}


    std::unique_ptr<Node> build_tree(int i, int j) {
        int m = (i+j)/2;

        std::unique_ptr<Node> t = std::make_unique<Node>();

        t->regions_len = 0;
        t->cnt = 0;

        t->B = pos[i];
        t->E = pos[j];
        t->M = pos[m];

        t->left = (i+1 < j ? build_tree(i, m) : nullptr);
        t->right = (i+1 < j ? build_tree(m, j) : nullptr);

        return t;
    }

    void insert(const Interval &I, int c) {
        insert(root.get(), I, c);
    }

    void insert(Node *v, const Interval &I, int c) {
        if (v == nullptr) return;

        if (I.low <= v->B && v->E <= I.high) {
            v->cnt += c;
            propagate(v, I);
        } else {
            if (I.low < v->M) insert(v->left.get(), I, c);
            if (I.high > v->M) insert(v->right.get(), I, c);
            propagate(v, I);
        }
    }

    void propagate(Node *v, const Interval &I) {
        if (v->cnt != 0) {
            v->regions_len = v->E - v->B;
        } else {
            int left_regions_len = (v->left != nullptr) ? v->left->regions_len : 0;
            int right_regions_len = (v->right != nullptr) ? v->right->regions_len : 0;

            v->regions_len = left_regions_len + right_regions_len;
        }
    }
};


struct Event
{
    int x;
    int type;
    int id;

    Event(int x, int type, int id)
        :x(x), type(type), id(id) {}

    bool operator<(const Event &e) const {
        return x != e.x ? x < e.x : type > e.type;
    }
};


int union_area2(std::vector<Rectangle> &r)
{
    int n = r.size();
    std::vector<Event> Qv, Qh;

    for (int i = 0; i < r.size(); i++) {
        Qv.push_back(Event(real(r[i][0]), 0, i));
        Qv.push_back(Event(real(r[i][1]), 1, i));

        Qh.push_back(Event(imag(r[i][0]), 1, i));
        Qh.push_back(Event(imag(r[i][1]), 0, i));
    }

    std::sort(Qv.begin(), Qv.end());
    std::sort(Qh.begin(), Qh.end());

    int area = 0.0;
    std::vector<bool> in_set(n);

    in_set[Qv[0].id] = true;
    for (int i = 1; i < Qv.size(); ++i) {
        int cnt = 0;
        int delta_x = Qv[i].x - Qv[i-1].x;
        int begin_y;

        if (delta_x == 0) {
            in_set[Qv[i].id] = (Qv[i].type == 0);
            continue;
        }

        for (int j = 0; j < Qh.size(); ++j) {
            if (in_set[Qh[j].id]) {
                if (Qh[j].type == 0) {
                    if (cnt == 0) begin_y = Qh[j].x;
                    ++cnt;
                } else {
                    --cnt;
                    if (cnt == 0) {
                        int delta_y = Qh[j].x - begin_y;
                        area += delta_x * delta_y;
                    }
                }
            }
        }

        in_set[Qv[i].id] = (Qv[i].type == 0);
    }

    return area;
}


long long union_area3(std::vector<Rectangle> &r)
{
    int n = r.size();
    std::vector<Position> pos;

    for (int i = 0; i < r.size(); i++) {
        pos.push_back(real(r[i][0]));
        pos.push_back(real(r[i][1]));
    }
    std::sort(pos.begin(), pos.end());
    pos.resize(std::unique(pos.begin(), pos.end()) - pos.begin());

    SegmentTree T(pos);

    std::vector<Event> Q;
    for (int i = 0; i < r.size(); i++) {
        Q.push_back(Event(imag(r[i][0]), 1, i));
        Q.push_back(Event(imag(r[i][1]), 0, i));
    }
    std::sort(Q.begin(), Q.end());

    long long area = 0LL;
    for (int i = 0; i < Q.size(); i++) {
        if (Q[i].type == 0) {
            int l = real(r[Q[i].id][0]);
            int h = real(r[Q[i].id][1]);
            //std::cout << l << ", " << h << std::endl;

            if (i > 0) {
                area += (static_cast<long long>(T.root->regions_len)) * (static_cast<long long>((Q[i].x - Q[i-1].x)));
            }

            T.insert(Interval(l, h), 1);
            //std::cout << "total: " << T.root->regions_len << std::endl;
        } else {
            int l = real(r[Q[i].id][0]);
            int h = real(r[Q[i].id][1]);
            //std::cout << l << ", " << h << std::endl;
            area += (static_cast<long long>(T.root->regions_len)) * (static_cast<long long>((Q[i].x - Q[i-1].x)));
            T.insert(Interval(l, h), -1);
        }
    }

    return area;
}


int main(void)
{
    int n;
    int x1, y1, x2, y2;

    std::cin >> n;
    std::vector<Rectangle> recs;

    REP(i, n) {
        std::cin >> x1 >> x2 >> y2 >> y1;
        recs.push_back(Rectangle(Point(x1, y1), Point(x2, y2)));
    }

    auto area = union_area3(recs);
    std::cout << area << std::endl;
    return 0;
}
