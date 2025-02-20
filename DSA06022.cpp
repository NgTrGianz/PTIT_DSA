#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

int bin_search(int a[], int l, int r, int x){
    int ans = -1;
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] == x){
            l = m + 1;
        } else if (a[m] < x){
            l = m + 1;
        } else {
            ans = m;
            r = m - 1;
        }
    }
    return ans;
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
        sort(a, a + n);
        int pos = bin_search(a, 0, n - 1, a[0]);
        if (pos == -1){
            cout << "-1" << endl;
        } else {
            cout << a[0] << " " << a[pos] << endl;
        }
    }
}