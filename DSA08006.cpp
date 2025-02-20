#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

ll ans(int n){
    queue<ll> q;
    q.push(9);
    while (!q.empty()){
        ll cur = q.front(); q.pop();
        if (cur % n == 0) return cur;
        q.push(cur * 10);
        q.push(cur * 10 + 9);
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << ans(n) << endl;
    }
}