#include<bits/stdc++.h>
using namespace std;

bool check(string s,string t){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) cnt++;
    }
    if(cnt == 1) return true;
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        string s,t;
        cin >> n >> s >> t;
        vector<string> v(n);
        int start = 0, end = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] == s) start = i;
            if (v[i] == t) end = i;
        }
        queue<pair<int, int>> q;
        set<int> checked_index;
        q.push({start, 1});
        checked_index.insert(start);
        while (!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            if (cur.first == end){
                cout << cur.second << endl;
                break;
            }
            for (int i = 0; i < n; i++){
                if (check(v[cur.first], v[i]) && checked_index.count(i) == 0){
                    q.push({i, cur.second + 1});
                    checked_index.insert(i);
                }
            }
        }
    }
}