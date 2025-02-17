#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int n;

void gene (string tmp){
    if (tmp.size() == n){
        ans.push_back(tmp);
    } else {
        if (tmp.size() < n){
            gene(tmp + "A");
            gene(tmp + "B");
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        gene("");
        for (auto x : ans){
            cout << x <<  " ";
        }
        cout << endl;
        ans.clear();
    }
}