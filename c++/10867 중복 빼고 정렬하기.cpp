#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int> s;
    for (int i = 0; i<n; i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    for(auto x : s){
        cout<<x<<' ';
    }
    return 0;
}
