#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v[100][100];

bool isAllSame(int sx, int sy, int size){
    int ch = v[sy][sx];
    for(int i = sy; i<(sy + size); i++){
        for(int j = sx; j<(sx+size); j++){
            if(ch != v[i][j]) return false;
        }
    }
    return true;
}


void zipQuard(int sx, int sy, int size){
    int n = size/2;
    if (isAllSame(sx, sy, size)){
         cout<<v[sy][sx];         
    }
    else{
        cout<<"(";
        zipQuard(sx, sy, n);
        zipQuard(sx+n, sy, n);
        zipQuard(sx, sy+n, n);        
        zipQuard(sx+n, sy+n, n);
        cout<<")";
    }    
}

int main()
{
    int n;
    
    freopen("input.txt", "r", stdin);
    scanf("%d\n", &n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%1d", &v[i][j]);
        }
        scanf("%*c");
    }    
    zipQuard(0, 0, n);

    return 0;
}
