#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> preorder;
vector<int> inorder;
int root = 0;

void printPostOrder(int from, int to){
    if(from == to) return;
    for(int i = from; i<to; i++){
        if(preorder[root] == inorder[i]){
            root++;
            if(from != i) printPostOrder(from, i);
            if(i+1 != to) printPostOrder(i+1, to);
            printf("%d\n",inorder[i]);
            return;
        }
    }
}

int main()
{
    freopen("test.txt", "r", stdin);
    int x;    
    while(scanf("%d",&x)==1){
        preorder.push_back(x);
    }
    inorder = preorder; 
    sort(inorder.begin(), inorder.end());
    printPostOrder(0, preorder.size());

    return 0;
}
