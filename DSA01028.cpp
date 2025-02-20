#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void gen(vector<int> a, int n, int k, int start, map<int, int> fre){
    if (a.size() == k){
        ans.push_back(a);
    } else {
        for (int i = start + 1; i <= n; i++){
            if (fre[i] == 0){
                a.push_back(i);
                fre[i] = 1;
                gen(a, n, k, i, fre);
                fre[i] = 0;
                a.pop_back();
            }
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    set<int> se;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        se.insert(x);
    }
    for (auto x : se){
        a.push_back(x);
    }
    map<int, int> fre;
    vector<int> tmp;
    gen(tmp, a.size(), k, 0, fre);
    for (auto v : ans){
        for (auto x : v){
            cout << a[x - 1] << " ";
        }
        cout << endl;
    }
}