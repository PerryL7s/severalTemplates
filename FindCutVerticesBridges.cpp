#include <bits/stdc++.h>
using namespace std;

class FindCutVerticesBridges
{
private:
    const int pointNum;
    vector<vector<int>> &adjaTable;

    int cnt = 0;
    int curRoot;
    int rootChildren;
    vector<int> low, depth, parent;

public:
    // results
    vector<int> isCutVertex;
    vector<vector<int>> bridge;

private:
    void dfs(int v)
    {
        low[v] = depth[v] = cnt++;
        int size = adjaTable[v].size();
        int nv;
        for (int i = 0; i < size; ++i)
        {
            nv = adjaTable[v][i];
            if (depth[nv] == -1)
            {
                parent[nv] = v;
                if (v == curRoot)
                    ++rootChildren;
                dfs(nv);
                if (low[nv] >= depth[v]) // for cut vertices
                    isCutVertex[v] = 1;
                if (low[nv] > depth[v]) // for bridges
                    bridge.emplace_back(vector<int>{v, nv});
                low[v] = min(low[v], low[nv]);
            }
            else if (nv != parent[v])
                low[v] = min(low[v], depth[nv]);
        }
    }

public:
    FindCutVerticesBridges(int n, vector<vector<int>> &input) : pointNum(n), adjaTable(input),
                                                                low(pointNum), depth(pointNum, -1), parent(pointNum), isCutVertex(pointNum, 0)
    {
        for (int i = 0; i < pointNum; ++i)
        {
            if (depth[i] == -1)
            {
                curRoot = i;
                rootChildren = 0;
                dfs(i);
                isCutVertex[curRoot] = (rootChildren > 1);
            }
        }
    }
};