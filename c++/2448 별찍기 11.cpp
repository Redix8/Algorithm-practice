#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char m[4000][7000];


void printStar(int x, int y, int size){
    int n = size/2;
    if(size ==3){
        m[y][x] = '*';
        m[y+1][x-1] = '*';
        m[y+1][x+1] = '*';
        for(int i=-2; i<3; i++) m[y+2][x+i] = '*';
    }
    else{
        printStar(x, y, n);
        printStar(x-n, y+n, n);
        printStar(x+n, y+n, n);        
    }
    return;
}



int main()
{
    int n ;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<2*n; j++){
            m[i][j] = ' ';
        }
    }
    printStar(n-1,0,n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<2*n; j++){
            cout<< m[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
