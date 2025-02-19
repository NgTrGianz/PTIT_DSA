#include<bits/stdc++.h>
using namespace std;

int find (int a[], int l, int r, int x){
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] == x) return m + 1;
        else if (a[m] > x){
            r = m - 1;
        } else{
            l = m + 1;
        }
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;
        int a[n];
        for (auto &k : a){
            cin >> k;
        }
        if (find(a, 0, n - 1, x) == -1){
            cout << "NO\n";
        } else {
            cout << find(a, 0, n - 1, x) << endl;
        }
    }
}