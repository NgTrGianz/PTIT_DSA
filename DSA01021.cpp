#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;
int ans (vector<int> a, int n, int k){
    vector<int> tmp(a);
    int i = a.size() - 1;
    while (i >= 0 && tmp[i] == n - k + i + 1){
        --i;
    }
    if (i == -1){
        return k;
    }
    tmp[i]++;
    for (int j = i + 1; j < k; j++){
        tmp[j] = tmp[j - 1] + 1;
    }
    int cnt = 0;
    map<int, int> f;
    for (int i = 0; i < k; i++){
        f[a[i]]++;
    }
    for (int i = 0; i < k; i++){
        if (f[tmp[i]] == 0){
            ++cnt;
        }
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++){
            cin >> a[i];
        }
        cout << ans(a, n, k);
        cout << endl;
    }
}