//finding the modular exponentiation. 
// c = a^n mod p where p is a prime number
//same logic as binary expo, but % p is added in the equations. 

#include<bits/stdc++.h>
using namespace std; 

int moduloExpo(int base, int n, int p)
{
    int res = 1; 

    while(n)
    {
        if(n%2)
        {
            res = (res * base) % p; 
            n--; 
        }

        else 
        {
            base = (base*base) % p; 
            n/=2; 
        }
    }
    return res; 
}

int main()
{
    int base, n, p; 
    cin>>base>>n>>p;
    cout<<moduloExpo(base, n, p)<<endl;
}