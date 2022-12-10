#include<bits/stdc++.h>
using namespace std; 

//sieve of erathothenes. finding prime numbers in a large range 
//where iterations till sqrt n will give TLE; 

//running time of this algorithm is O(n log log n);

int main()
{
    int t; 
    cin>>t; 
    while(t--)
    {
        int maxN = 1000000; 
        int isPrime[1000001];

        for(int i=1; i<=maxN; i++)
        {
            isPrime[i] = 1; 
            isPrime[1] = isPrime[0] = 0; 
        }

        for(int i=2; i*i<=maxN; i++)
        {
            if(isPrime[1])
            {
                for(int j=i*i; j<=maxN; j+=i)
                {
                    isPrime[j] = 0; 
                }
            }
        }
    }
}