//binary exponentiation allows us to find a^n in O(nlogn) time complexity
//given integers a and n, find the value. 

//brute force: 
//time complexity is about O(n); (liner in n)

#include<bits/stdc++.h>
#include<math.h>
using namespace std; 

int expo(int base, int n)
{
    int res = 1; 
    
    while(n)
    {
        if (n%2)
        {
            res *= base;                                
            n--; 
        }
        else 
        {
            base *= base; 
            n/=2; 
        }
    }

    return res; 
}


int power(int base, int n)
{
    int res = 1; 

    for(int i=1; i<=n; i++)
    {
        res = res * base; 
    }

    return res; 
}

int main()
{
    int base, n; 

    cin>>base>>n; 
    cout<<power(base,n)<<endl;
    cout<<expo(base, n)<<endl;

    return 0; 


}