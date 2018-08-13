#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > tree(27, vector<int>(2));

void preorder(int node){
    if(node == -1) return;
    printf("%c", node+'A');
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

void inorder(int node){
    if(node == -1) return;
    if(tree[node][0]!=-1) inorder(tree[node][0]);
    printf("%c", node+'A');
    inorder(tree[node][1]);
}

void postorder(int node){
    if(node == -1) return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    printf("%c", node+'A');
}

int main()
{
    int N;
    char node, left, right;
    cin >> N;    
       
    for(int i=0; i<N ; i++){
        scanf(" %c %c %c", &node, &left, &right);
        
        left = (left != '.') ? (left-'A') : -1;
        right = (right != '.') ? (right-'A') : -1;
//        cout<<(int)left<<" "<<(int)right <<"\n";
        tree[node-'A'][0] = left;
        tree[node-'A'][1] = right;
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    return 0;
}


