#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int fre[100] ;
void gen(vector<int> a, int n, int k, int start){
    if (a.size() == k){
        ans.push_back(a);
        return ;
    } else {
        for (int i = start + 1; i <= n; i++){
            a.push_back(i);
            if(a[0] <= n - k + 1) gen(a, n, k, i);
            a.pop_back();
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    int t = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        t = max(t, x);
    }
    vector<int> a;
    gen(a, t, k, 0);
    for (auto v : ans){
        for (auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }
}