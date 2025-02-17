#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

ll bin_pow(int n, int k){
    if (k == 0) return 1;
    else {
        ll x = bin_pow(n, k / 2);
        if (k%2 == 0) return x * x % mod;
        else return x * x * n % mod;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        cout << bin_pow(n, k) << endl;
    }
}