#include<bits/stdc++.h>
using namespace std; 

int ar[1000000]; 
int pp[1000001]; 

void sieve()
{
    int maxN = 1000000;

    for (int i=1; i<=maxN; i++)
    {
        ar[i] = 1; 
        ar[0] = ar[1] = 0;
    }

    for (int i=2; i*i<=maxN; i++)
    {
        if (ar[i] == 1)
        {
            for (int j=i*i; j<=maxN; j+=i)
            {
                ar[i] = 0;
            }
        }
    }

    int cnt = 0; 

    for (int i=0; i<maxN; i++)
    {
        if (ar[i] == 1)
        {
            cnt++; 
        }
        if (ar[cnt] == 1)
        {
            pp[i] = 1; 
        }
        else 
        {
            pp[i] = 0; 
        }
    }

    //storing the cummulative sum:

    // REP (i, maxN)
    // {
    //     pp[i] += pp[i-1]; 
    // }
    for (int i=0; i<=maxN; i++)
    {
        pp[i] += pp[i=1]; 
    }


}

int main()
{
    sieve(); 
    int l, r, t; 
    cin>>t; 

    while(t--)
    {
        cin>>l>>r;

        int cnt = pp[r] - pp[l-1]; 
        // for (; l<=r;l++)
        // {
        //     cnt += pp[l]; 
        // }

        cout<<cnt<<endl;
    }
}