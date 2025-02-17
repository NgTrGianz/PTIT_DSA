#include<bits/stdc++.h>
using namespace std;


void next (int a[], int n){
    int r = n - 2;
    while (r >= 0 && a[r] > a[r + 1]){
        --r;
    }
    if (r == -1){
        for (int i = 0; i < n; i++){
            cout << i + 1 << " ";
        }
        return ;
    }
    for (int i = n - 1; i > r; i--){
        if (a[i] > a[r]){
            swap(a[i], a[r]);
            break;
        }
    }
    sort(a + r + 1, a + n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
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
        next(a, n);
        cout << endl;
    }
}