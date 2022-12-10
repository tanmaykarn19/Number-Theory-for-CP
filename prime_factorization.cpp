//do the prime factorization of the given n; 

//using brute force:: 
//worst case - O(n).

//optimised using primality test: 
//time complexity would be O(sqrt(n)); 
#include<bits/stdc++.h>
using namespace std; 

void primeFact(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0)
        {
            int cnt = 0; 
            while(n % i == 0)
            {
                cnt++; 
                n/=i; 
            }
            cout<<i<<" ^ "<<cnt<<endl;                       
        }

    }
        if(n>1)
        {
            cout<<n<<" ^ "<<1<<endl;
        }
}

int main()
{
    int n; 
    cin>>n; 
    primeFact(n); 

    return 0;
}