#include <bits/stdc++.h>
using namespace std;

class KMP
{
private:
    string &s;
    string &p;
    int sLen;
    int pLen;
    vector<int> next;

public:
    KMP(string &_s, string &_p) : s(_s), p(_p), sLen(s.size()), pLen(p.size()), next(pLen)
    {
        next[0] = -1;
        int i = -1, j = 0;
        while (j < pLen - 1)
        {
            if (i == -1 || p[j] == p[i])
            {
                ++i;
                ++j;
                next[j] = i;
            }
            else
            {
                i = next[i];
            }
        }
    }

    int find()
    {
        int i = 0, j = 0;
        while (i < sLen && j < pLen)
        {
            if (j == -1 || s[i] == p[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == pLen)
            return i - j;
        else
            return -1;
    }
};