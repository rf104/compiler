#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            //int k = b/2;
            if(b%2==1) cout<<b+1<<"\n";
            else cout<<b/2<<"\n";
        }
        else
        {
            cout<<b/a+1<<"\n";
        }
    }
}
