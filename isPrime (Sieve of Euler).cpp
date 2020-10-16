#include <bits/stdc++.h>
using namespace std;


class isPrime
{
private:
    const int MAXN;
    vector<int> isPrimeArr;
    vector<int> primeArr;

public:
    isPrime(int n) : MAXN(n + 1), isPrimeArr(MAXN, 1)
    {
        isPrimeArr[0] = isPrimeArr[1] = 0;
        int i, j, size = 0, comp;
        for (i = 2; i < MAXN; ++i)
        {
            if (isPrimeArr[i] == 1)
            {
                primeArr.emplace_back(i);
                ++size;
                for (j = 0; j < size && (comp = i * primeArr[j]) < MAXN; ++j)
                    isPrimeArr[comp] = 0;
            }
            else
            {
                for (j = 0; j < size && (comp = i * primeArr[j]) < MAXN; ++j)
                {
                    isPrimeArr[comp] = 0;
                    if (i % primeArr[j] == 0)
                        break;
                }
            }
        }
    }

    bool judge(int i)
    {
        return isPrimeArr[i];
    }
};