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
    ll a, b;
    cin >> a >> b;
    while (a != 0 || b != 0){
        cout << bin_pow(a, b) << endl;
        cin >> a >> b;
    }
}