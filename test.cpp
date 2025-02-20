#include<bits/stdc++.h>
using namespace std;
using str = string;
long long cal (long long a, int b, char x){
    if (x == '*') return a * b;
    else if (x == '-') return a - b;
    else if (x == '/') return a / b;
    else return a + b;
}
long long ans (str s){
    stack<long long> st;
    for (auto x : s){
        if (isdigit(x)){
            st.push(x - '0');
        } else {
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            st.push(cal(b, a, x));
        }
    }
    return st.top();
}
int main(){
    str a;
    cin >> a;
    cout << ans(a);
}