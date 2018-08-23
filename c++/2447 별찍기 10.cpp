#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char m[7000][7000];


void drawStar(int x, int y, int size, char c){
    if(size == 1){
        m[y][x] = c;
        return;
    }
    int n = size/3;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i==1 && j == 1){
                drawStar(x+n, y+n, n, ' ');
            }
            else{
                if(c==' ') drawStar(x+n*j, y+n*i, n, ' ');
                else drawStar(x+n*j, y+n*i, n, '*');
            }
        }
    }
}


int main()
{
    int n;
    cin>>n;
    drawStar(0, 0, n, '*');
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<m[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
