#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;    
    list<pair<int,int>> L;
    for (int i = 1; i<=n; i++){
        int a;
        cin>>a;
        L.push_back({a,i});    
    }

    auto it = L.begin();
    for (int i=0; i<n-1; i++){
        cout<< (it->second) << ' ';
        int step = it->first;
        if (step > 0){
            auto temp = it;
            temp++;
            if(temp == L.end()) temp = L.begin();
            L.erase(it);
            it = temp;
            for (int i = 1; i<step; i++){
                it++;
                if(it==L.end()) it = L.begin();
            }
        }
        else if(step <0){
            step = -step;
            auto temp = it;
            if(temp == L.begin()) temp = L.end();
            temp--;
            L.erase(it);
            it = temp;
            for(int i =1; i<step; i++){
                if(it == L.begin()) it= L.end();
                it--;
            }
        }
    }
    cout << L.front().second << "\n";

    return 0;
}
