#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

ll ans(ll n){
    queue<ll> q;
    q.push(1);
    while (1){
        ll cur = q.front(); q.pop();
        if (cur % n == 0) return cur;
        q.push(cur * 10);
        q.push(cur * 10 + 1);
    }
    return -1;
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