#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int n, k;

void gene (string tmp, int cnt){
    if (tmp.size() > n) return ;
    if (tmp.size() == n && cnt == k){
        ans.push_back(tmp);
        return ;
    } else {
        gene(tmp + "0", cnt);
        if(cnt < k) gene(tmp + "1", cnt + 1);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        ans.clear();
        cin >> n >> k;
        gene("", 0);
        for (auto x : ans){
            cout << x << endl;
        }
    }
}