#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;
string prev_binary(string s){
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0'){
        s[i] = '1';
        --i;
    }
    if (i == -1){
        return s;
    }
    s[i] = '0';
    return s;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        cout << prev_binary(s);
        cout << endl;
    }
}