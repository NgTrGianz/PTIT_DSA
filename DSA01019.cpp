#include<bits/stdc++.h>
using namespace std;
vector<string> ans;

void Gen_HAHA(string tmp, int n){
    if (tmp.size() == n){
        ans.push_back((tmp + "A"));
        return ;
    } else {
        char last = tmp.back();
        if (last == 'H'){
            Gen_HAHA(tmp + "A", n);
        } else {
            Gen_HAHA(tmp + "A", n);
            Gen_HAHA(tmp + "H", n);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ans.clear();
        int n;
        cin >> n;
        Gen_HAHA("H", n - 1);
        for (auto x : ans){
            cout << x << endl;
        }
    }
}