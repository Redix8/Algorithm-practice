#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[100001];
int answer[100001];


void searchParent(int node, int parent){
    for(auto x : tree[node]){
        if(x == parent) {
            answer[node] = parent;        
        }
        else{
            searchParent(x, node);
        }         
    }
    return;
}


int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;

    for(int i =0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    searchParent(1,1);
    for(int i = 2; i<n+1; i++){
        cout<<answer[i]<<"\n";
    }

    return 0;
}
