#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

int bin_search(int a[], int l, int r, int x){
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] == x){
            return 1;
        } else if (a[m] < x){
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
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
        sort(a, a + n);
        cout << bin_search(a, 0, n - 1, k) << endl;
    }
}