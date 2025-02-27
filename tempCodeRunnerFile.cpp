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
 
bool cmp (string a, string b){
    return check(a, b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        string s,t;
        cin >> n >> s >> t;
        set<string> se;
        vector<string> v;
        for (int i = 0; i < n; i++){
            string tmp; cin >> tmp;
            se.insert(tmp);
        }
        for (auto x : se){
            v.push_back(x);
        }
        int start, end;
        vector<int> list[v.size()];
        sort(v.begin(), v.end(), cmp);
        for (int i = 1; i < v.size(); i++){
            if (v[i] == s) start = i;
            if (v[i] == t) end = i;
            list[i - 1].push_back(i);
        }
        queue<pair<int , int>> q;
        q.push({start, 1});
        set<int> checked;
        checked.insert(start);
        while (q.size()){
            auto cur = q.front(); q.pop();
            int cur_index = cur.first;
            int cnt = cur.second;
            if (cur_index == end){
                cout << cnt << endl;
                break;
            }
            for (int i = 0; i < list[cur_index].size(); i++){
                if (checked.count(list[cur_index][i]) == 0){
                    q.push({list[cur_index][i], cnt + 1});
                }
            }
        }
    }
}
// 1
// 8 giang ggang 
// giang nguyen truong giang helloo giang ggang giang