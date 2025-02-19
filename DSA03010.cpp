#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans (int a[], int n){
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++){
        pq.push(a[i]);
    }
    ll sum = 0;
    while (pq.size() != 1){
        ll tmp = 0;
        tmp += pq.top(); pq.pop();
        tmp += pq.top(); pq.pop();
        pq.push(tmp);
        sum += tmp;
    }
    return sum;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (auto &x : a){
            cin >> x;
        }
        cout << ans(a, n) << endl;
    }
}