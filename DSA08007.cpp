#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

int ans(ll n){
    queue<ll> q;
    q.push(1);
    int cnt = 0;
    while (1){
        ll cur = q.front(); q.pop();
        if (cur > n) break;
        ++cnt;
        q.push(cur * 10);
        q.push(cur * 10 + 1);
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << ans(n);
        cout << endl;
    }
}