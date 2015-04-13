#include <vector>
#include <iterator>
#include <algorithm>
#include "utils/segment_tree.h"

int main(void)
{
    std::vector<int> pos {0, 8, 10, 11, 1000, 1006, 1009};
    SegmentTree<int> T(pos);

    T.insert(Interval(8, 10), 1);
    T.insert(Interval(8, 1000), 2);
    auto&& output = T.query(9);

    std::sort(output.begin(), output.end());
    std::copy(output.begin(), output.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
