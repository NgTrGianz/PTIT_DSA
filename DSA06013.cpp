#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

ll bin_pow(ll n, ll k){
    if (k == 0) return 1;
    else {
        ll x = bin_pow(n, k / 2);
        if (k % 2 == 1){
            return (x * x) % mod * n % mod;
        } else {
            return x * x % mod;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            cnt[x]++;
        }
        cout << (cnt[k] == 0 ? -1 : cnt[k]) << endl;
    }
}