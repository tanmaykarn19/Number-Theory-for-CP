//better approach to check if a number is prime or not. 

#include<bits/stdc++.h>
using namespace std; 

bool isPrime(int n)
{
    if (n == 1) return false; 

    for (int i=2; i*i<=n; i++)
    {
        if (n % i == 0) return false; 
    }

    return true;

    //hence the loop runs for i to sqrt(n), the time complexity is O(sqrt(N)).
}

int main()
{
    int t, n; 
    cin>>t; 
    while(t--)
    {
        cin>>n; 

        if(isPrime(n)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}