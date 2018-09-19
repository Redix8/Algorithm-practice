#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int m[5000000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        m[i] = x;
    }
    nth_element(m, m+(k-1), m+n );
    cout<<m[k-1];

}