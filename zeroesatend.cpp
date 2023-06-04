#include<bits/stdc++.h>
using namespace std;

void push_zeroes_end_(vector<int>& arr)
{
    stable_partition(arr.begin(),arr.end(),[](int n){return n!=0;});
}

int main()
{
    
    vector<int> arr{4,0,5,6,3,0,7,1,0,3,0,8,5};
    push_zeroes_end_(arr);

    for(const auto& i: arr)
    {
        cout<<i<<" ";

    }
    cout<<"\n";

    return 0;

}