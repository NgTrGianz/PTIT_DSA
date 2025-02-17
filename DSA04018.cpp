#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

int bin_search(int a[], int l, int r, int x){
    int last = -2, first = -1;
    int l1 = l, l2 = l;
    int r1 = r, r2 = r;
    while (l1 <= r1){
        int m = (l1 + r1) / 2;
        if (a[m] == x){
            first = m;
            r1 = m - 1;
        } else if (a[m] < x){
            l1 = m + 1;
        } else {
            r1 = m - 1;
        }
    }
    while (l2 <= r2){
        int m = (l2 + r2) / 2;
        if (a[m] == x){
            last = m;
            l2 = m + 1;
        } else if (a[m] < x){
            l2 = m + 1;
        } else {
            r2 = m - 1;
        }
    }
    return last - first + 1;
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
        cout << bin_search(a, 0, n - 1, 0) << endl;
    }
}