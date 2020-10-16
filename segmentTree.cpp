#include <bits/stdc++.h>
using namespace std;


class egmentTree
{
private:
    struct Node
    {
        int l;
        int r;
        int sum;
        int tag;
    };
    int num;
    vector<int> &input;
    vector<Node> tree;

    void buildTree(int i, int l, int r)
    {
        tree[i].l = l, tree[i].r = r, tree[i].tag = 0;
        if (l == r)
        {
            tree[i].sum = input[l];
            return;
        }
        int mid = (l + r) >> 1, lChild = (i << 1) | 1, rChild = lChild + 1;
        buildTree(lChild, l, mid);
        buildTree(rChild, mid + 1, r);
        tree[i].sum = tree[lChild].sum + tree[rChild].sum;
    }

public:
    segmentTree(vector<int> &_input) : input(_input), num(input.size()), tree(4 * num)
    {
        buildTree(0, 0, num - 1);
    }

    void add(int l, int r, int k, int i = 0)
    {
        if (tree[i].l > r || tree[i].r < l)
            return;
        if (tree[i].l >= l && tree[i].r <= r)
        {
            tree[i].tag += k;
            tree[i].sum += (tree[i].r - tree[i].l + 1) * k;
            return;
        }
        int lChild = (i << 1) | 1, rChild = lChild + 1;
        tree[rChild].tag += tree[i].tag;
        tree[rChild].sum += (tree[rChild].r - tree[rChild].l + 1) * tree[i].tag;
        tree[lChild].tag += tree[i].tag;
        tree[lChild].sum += (tree[lChild].r - tree[lChild].l + 1) * tree[i].tag;
        tree[i].tag = 0;
        add(l, r, k, rChild);
        add(l, r, k, lChild);
        tree[i].sum = tree[rChild].sum + tree[lChild].sum;
    }

    int get(int l, int r, int i = 0)
    {
        if (tree[i].l > r || tree[i].r < l)
            return 0;
        if (tree[i].l >= l && tree[i].r <= r)
            return tree[i].sum;
        int lChild = (i << 1) | 1, rChild = lChild + 1;
        tree[rChild].tag += tree[i].tag;
        tree[rChild].sum += (tree[rChild].r - tree[rChild].l + 1) * tree[i].tag;
        tree[lChild].tag += tree[i].tag;
        tree[lChild].sum += (tree[lChild].r - tree[lChild].l + 1) * tree[i].tag;
        tree[i].tag = 0;
        return get(l, r, rChild) + get(l, r, lChild);
    }
};
