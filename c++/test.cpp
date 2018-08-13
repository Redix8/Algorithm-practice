#include <iostream>
#include <vector>
using namespace std;

main(int argc, char const *argv[])
{
    vector<int> a = {1, 2, 3};

    auto it = a.begin();
    a.insert(it, 4);
    it = a.begin()+1;
    a.insert(it, 5, 0);
    for (auto &x : a){
        cout<< x << ' ' ;
    }
    cout<<"\n";

    it = a.begin() +2;
    vector<int> b = {10, 20};
    a.insert(it, b.begin(), b.end());
    for (auto &x : a){
        cout<< x << ' ' ;
    }
    cout<<"\n";


    return 0;
}
