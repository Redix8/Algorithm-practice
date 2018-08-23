#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
    for(int i = 1; i<=5; i++){
        auto it = find(a.begin(), a.begin()+8, i);
        cout << i << "of location: ";
        if (it == a.end()){
            cout << "not found";
        }
        else{
            cout << it-a.begin();
        }
        cout << '\n';
    }
    return 0;
}
