// compute the prime factorization using sieve
//  in log n time.

#include <bits/stdc++.h>
using namespace std;

int ar[1000001];

void sieve()
{
    int maxN = 1000000;
    for (int i = 0; i <= maxN; i++)
    {
        ar[i] = -1;
    }

    for (int i = 2; i <= maxN; i++)
    {
        if (ar[i] == -1)
        {
            for (int j = i; j <= maxN; j += i)
            {
                if (ar[j] == -1)
                {
                    ar[j] = i;
                }
            }
        }
    }
}

vector<int> getfactors(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(ar[x]);
        x = x / ar[x];
    }

    return ret;
}

int main()
{
    sieve();
    int n, t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> v = getfactors(n);

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}