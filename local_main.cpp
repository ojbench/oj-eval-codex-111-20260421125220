#include <bits/stdc++.h>
using namespace std;

#include "src.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; if(!(cin>>n)) return 0;
    for(int i=0;i<n;++i){
        int op; string s1,s2; cin>>op>>s1>>s2;
        if(op==1){
            vector<char> buf(s1.begin(), s1.end());
            buf.push_back('\0');
            vector<char> d(s2.begin(), s2.end());
            d.push_back('\0');

            char* token = strtok(buf.data(), d.data());
            while(token){
                cout << token << "\n";
                token = strtok(nullptr, d.data());
            }
        }
    }
    return 0;
}

