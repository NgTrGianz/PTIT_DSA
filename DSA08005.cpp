#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

void ans(int n){
    queue<ll> q;
    q.push(1);
    while (n--){
        ll cur = q.front(); q.pop();
        cout << cur << " ";
        q.push(cur * 10);
        q.push(cur * 10 + 1);
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        ans(n);
        cout << endl;
    }
}