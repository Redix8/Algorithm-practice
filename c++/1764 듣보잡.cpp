#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n, m, val;
    cin>>n>>m;
    map<string, int> s;    
    for(int i = 0; i<n ; i++){
        string str;
        cin>>str;
        s[str] += 1;
    }
    for(int i = 0; i<m; i++){
        string str;
        cin>>str;
        s[str] += 1;
    }
    for(auto x : s){
        if(x.second==2) val +=1;
    }
    cout<<val<<'\n';
    for(auto x : s){
        if(x.second==2){
            cout<<x.first<<'\n';
        }
    }
    return 0;
}
