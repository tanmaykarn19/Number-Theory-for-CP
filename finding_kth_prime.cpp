#include<bits/stdc++.h>
using namespace std; 

vector<int> primes; 
bool arr[90000001];

void sieve()
{
    int maxN = 90000000; 
    arr[0] = arr[1] = true; 

    for(int i=2; i*i<=maxN; i++)
    {
        if(arr[i] == false)
        {
            for(int j=i*i; j<=maxN; j+=i)
            {
                arr[j] = true; 
            }
        }
    }

    for(int i=2; i*i<=maxN; i++)
    {
        if (arr[i] == false)
        {
            primes.push_back(i); //i is stored. not the element of i i.e. true or false in boolean vector.
        }
    }
}

int main()
{
    int q, n; 
    cin>>q; 
    
    sieve(); 
    while(q--)
    {
        cin>>n; 
        cout<<primes[n-1]<<endl;
    }

    return 0;
    
}

