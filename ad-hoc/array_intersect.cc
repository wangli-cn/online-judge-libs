vector<int> find_intersection(vector<int> &a, vector<int> &b)
{
    vector<int> intersect;

    int n1 = a.size();
    int n2 = b.size();

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] > b[j]) j++;
        else if (a[i] < b[j]) i++;
        else {
            intersection.push_back(a[i]);
            i++; j++;
        }
    }

    return intersect;
}
