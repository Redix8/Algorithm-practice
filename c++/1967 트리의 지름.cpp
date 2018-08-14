#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int> > tree[10001];
int subm = 0;
int subtree(int node){
    if(tree[node].empty()) return 0;
    int ret = 0;
    int ret2 = 0;    
    for(auto x : tree[node]){
         int ch = x.first;
         int val = x.second;
                
         ret2 = max(ret2, val + subtree(ch));
         if(ret< ret2) swap(ret, ret2);
         //cout<<"node : " <<ch << " val : " << val <<" ret : " << ret<< "\n"; 
     }
    subm = max(subm, ret+ret2);
    
    return ret;
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n;    
    cin>>n;
    for(int i = 0; i<n-1; i++){
        int rt, ch, val;
        cin>>rt >> ch >> val;        
        tree[rt].push_back({ch, val});
    }

    subtree(1);
    cout << subm;
    return 0;
}



