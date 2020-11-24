#include <bits/stdc++.h>
using namespace std;

// Index starts from 1
class BinaryIndexedTree
{
private:
    int num;
    vector<int> tree;

    inline int lowBit(int n)
    {
        return n & (-n);
    }

public:
    void add(int pos, int n)
    {
        while (pos < num)
        {
            tree[pos] += n;
            pos += lowBit(pos);
        }
    }

    int prefixSum(int i)
    {
        int ans = 0;
        while (i)
        {
            ans += tree[i];
            i -= lowBit(i);
        }
        return ans;
    }

    BinaryIndexedTree(int n) : num(n + 1), tree(num, 0)
    {
        int x;
        for (int i = 0; i < num; ++i)
        {
            cin >> x;
            add(i, x);
        }
    }
};