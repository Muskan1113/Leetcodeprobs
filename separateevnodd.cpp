#include<bits/stdc++.h>
using namespace std;

void separate_even_odd(vector<int>m)
{
    stable_partition(m.begin(),m.end(),[](auto n){return n%2==0;});

    for(int num:m)
    {
        cout<<num<<" ";
    }
}

int main()
{
    
    vector<int>m={4,0,5,6,3,0,7,1,0,3,0,8,5};
    separate_even_odd(m);

    return 0;

}