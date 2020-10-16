#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> root;
    int n;

    int findRoot(int i)
    {
        if (root[i] == i)
            return i;
        return root[i] = findRoot(root[i]);
    }

public:
    DisjointSet(int _n) : n(_n), root(n)
    {
        for (int i = 0; i < n; ++i)
            root[i] = i;
    }

    bool isSameRoot(int i, int j)
    {
        if (findRoot(i) == findRoot(j))
            return true;
        return false;
    }

    void merge(int i, int j)
    {
        if (isSameRoot(i, j))
            return;
        root[i] = root[j];
    }
};