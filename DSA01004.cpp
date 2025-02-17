#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;
void gen (vector<int> &a, int n, int k, int start){
    if (a.size() == k){
        for (int i = 0; i < k; i++){
            cout << a[i];
        }
        cout << " ";
    } else {
        for (int i = start; i <= n; i++){
            a.push_back(i);
            gen(a, n, k, i + 1);
            a.pop_back();
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        vector<int> a;
        cin >> n >> k;
        gen(a, n, k, 1);
        cout << endl;
    }
}