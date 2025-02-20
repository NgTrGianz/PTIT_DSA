#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

void gene(int n){
    queue<str> q;
    q.push("6");
    q.push("8");
    stack<str> st;
    vector<str> ans;
    while (1){
        str cur = q.front(); q.pop();
        if (cur.size() > n) break;
        ans.push_back(cur);
        st.push(cur);
        q.push(cur + "6");
        q.push(cur + "8");
    }
    cout << ans.size() << endl;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        gene(n);
    }
}