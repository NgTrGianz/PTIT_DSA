#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

str ans(str s){
    stack<str> st;
    for (auto x : s){
        str res = "";
        if (isalpha(x)){
            st.push(string(1, x));
        } else {
            res += x;
            str num1 = st.top(); st.pop();
            str num2 = st.top(); st.pop();
            res = "(" + num2 +res + num1 + ")";
            st.push(res);
        }
    }
    return st.top();
}

int main(){
    str s;
    cin >> s;
    cout << ans(s);
}