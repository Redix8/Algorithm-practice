#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> s = {{"black", 0},{"brown", 1}, {"red", 2},
                          {"orange",3}, {"yellow",4}, {"green",5},
                          {"blue", 6}, {"violet",7}, {"grey",8},
                          {"white",9}};
    string first, second, third;
    cin>>first>>second>>third;
    long long ret = s[first]*10LL +s[second];
    for(int i = 0; i<s[third]; i++){
        ret *=10LL;
    }
    cout<<ret;
    return 0;
}
