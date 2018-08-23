#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m[10001];
int k, n;
long long maxmid = 0;

void find(long long from, long long to){
    if(from > to) return;
    long long mid = (from+to)/2;
    int count = 0;
    for(int i = 0; i<k; i++){
        count += m[i]/mid;
    }
    if(count<n) find(1, mid-1);
    else {
        maxmid = max(maxmid, mid);
        find(mid+1, to);
    }
    return;
}

int main()
{    
    cin>>k >> n;
    int val = 0;
    for (int i = 0; i<k; i++){
        int x;
        cin>>x;        
        m[i] = x;
        val = max(val, x);
    }
    find(1, val);

    cout<<maxmid;
    
    return 0;
}
