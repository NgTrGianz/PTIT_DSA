#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        str a[n];
        set<char> digit;
        for (auto &x : a){
            cin >> x;
            for (auto c : x){
                digit.insert(c);
            }
        }
        for (auto x : digit){
            cout << x << " ";
        }
        cout << endl;
    }
}