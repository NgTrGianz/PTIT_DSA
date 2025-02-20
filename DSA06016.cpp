#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (auto &x : a){
            cin >> x;
        }
        for (auto &x : b){
            cin >> x;
        }
        sort(a, a + n);
        sort(b, b + m);
        cout << 1ll * a[n - 1] * b[0] << endl;
    }
}