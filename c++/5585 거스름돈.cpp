#include <iostream>
using namespace std;

int main(){
    int m;
    cin>>m;
    m = 1000 - m;
    int change;
    int coin[] = {500, 100, 50, 10, 5, 1};
    int i = 0, cnt = 0;    
    while(1){
        change = m/coin[i];
        cnt += change;
        if (change == 0) i++;
        else{
            m = m%coin[i];
            if(m == 0) break;
        }
    }
    cout<<cnt;
}