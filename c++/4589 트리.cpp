#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> slice(const vector<int>& v, int from, int to){
    return vector<int>(v.begin() + from, v.begin() + to);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
    const int N = preorder.size();
    if(preorder.empty()) return;
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    const int R = N - 1 - L;
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
    cout<<root<<" ";
}

int main()
{
    freopen("test.txt", "r", stdin);
    int T;
    cin>> T;        
    for(int i = 0; i<T; i++){
        vector<int> preorder;
        vector<int> inorder;
        int n;
        cin>>n;
        for (int j = 0; j<n; j++){
            int x;
            cin>>x;
            preorder.push_back(x);            
        }
        for (int j = 0; j<n; j++){
            int x;
            cin>>x;
            inorder.push_back(x);            
        }
        printPostOrder(preorder, inorder);
        cout<<"\n";
    }
    return 0;
}
