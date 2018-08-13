#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{    
    string s;
    cin>>s;
    list<char> A(s.begin(),s.end());
    int n;
    cin>>n;
    
    auto it = A.end();
    for(int i = 0; i<n; i++){
        char qr, c;
        cin>>qr;
        if (qr=='L'){
            if(it!=A.begin()){
                it--;
            }
        }
        else if(qr=='D'){
            if(it!=A.end()){
                it++;
            }
        }
        else if(qr=='B'){
            if(it!=A.begin()){
                auto temp = it;
                it--;
                A.erase(it);
                it = temp;                
            }
        }
        else if(qr=='P'){
            cin>>c;
            A.insert(it,c);
        }        
    }
    for(char c : A) cout<<c;
    cout<<'\n';

    return 0;
}
