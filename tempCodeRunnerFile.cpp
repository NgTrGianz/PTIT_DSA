#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;
int prio_level(char s){
    if (s == '(' || s == ')') return 0;
    else if (s == '+' || s == '-') return 1;
    else if (s == '^') return 4;
    else return 3;
}
str ans(str s){
    stack<char> st;
    str res = "";
    for (auto x : s){
        if (x == '('){
            st.push(x);
        } else if (isalpha(x)){
            res += x;
        } else if (x == ')'){
            while (st.top() != '('){
                res += st.top(); st.pop();
            }
            st.pop();
        } else {
            while (prio_level(st.top()) >= prio_level(x)){
                res += st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    return res;
}

int main(){
    str s;
    cin >> s;
    cout << ans(s);
}