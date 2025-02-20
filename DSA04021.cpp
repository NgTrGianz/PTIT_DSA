#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;

ll sz[93];

int ans (ll n, ll k){
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else {
        if (k <= sz[n - 2]) return ans(n - 2, k);
        else return ans(n - 1, k - sz[n - 2]);
    }
}
int main(){
    sz[1] = 1;
    for (int i = 2; i < 93; i++){
        sz[i] = sz[i - 2] + sz[i - 1];
    }
    int t;
    cin >> t;
    while (t--){
        ll n, k;
        cin >> n >> k;
        cout << ans(n ,k) << endl;
    }
}