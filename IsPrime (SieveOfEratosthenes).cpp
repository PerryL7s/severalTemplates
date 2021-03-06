#include <bits/stdc++.h>
using namespace std;

class isPrime
{
private:
    const int MAXN;
    vector<int> isPrimeArr;

public:
    isPrime(int n) : MAXN(n + 1), isPrimeArr(MAXN, 1)
    {
        isPrimeArr[0] = isPrimeArr[1] = 0;
        int i, j;
        for (i = 2; i <= MAXN / 2; ++i)
        {
            if (isPrimeArr[i] == 1)
            {
                for (j = i * i; j < MAXN; j += i) // trick: replace i + i by i * i since (2 - (i - 1)) have been searched
                    isPrimeArr[j] = 0;
            }
        }
    }

    bool judge(int i)
    {
        return isPrimeArr[i];
    }
};