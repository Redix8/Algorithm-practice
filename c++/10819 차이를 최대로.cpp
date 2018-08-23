#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    int maxsum = 0;;
    cin>>n;
    vector<int> a;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    
    do{
        int sum = 0;
        for(int i=1; i<n; i++){
            sum += abs(a[i] - a[i-1]);
        }
        maxsum = max(maxsum, sum);
    }
    while(next_permutation(a.begin(), a.end()));
    cout<<maxsum;
    
    return 0;
}
