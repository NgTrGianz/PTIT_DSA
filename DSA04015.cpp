#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

int bin_search(int a[], int l, int r, int x){
    int ans = -2;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] == x){
            ans = m;
            r = m - 1;
        } else if (a[m] < x){
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans + 1;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for (auto &x : a){
            cin >> x;
        }
        cout << bin_search(a, 0, n - 1, k) << endl;
    }
}