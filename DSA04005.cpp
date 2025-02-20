#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;

long long fibo[93];


char ans (ll n, ll k){
    if (n == 1) return 'A';
    else if (n == 2) return 'B';
    else {
        if (k <= fibo[n - 2]) return ans(n - 2, k);
        else return ans(n - 1, k - fibo[n - 2]);
    } 
}
int main(){
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i <= 92; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    int t;
    cin >> t;
    while (t--){
        long long n, k;
        cin >> n >> k;
        cout << ans(n, k) << endl;
    }
}