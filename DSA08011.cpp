#include<bits/stdc++.h>
using namespace std;

vector<string> get_neighbor(string word, unordered_set<string> &us) {
    vector<string> ans;
    string tmp = word;
    for (int i = 0; i < word.size(); i++) {
        char ori = tmp[i];
        for (char j = 'A'; j <= 'Z'; j++) {
            if (j == ori) continue; // Bỏ qua ký tự gốc
            tmp[i] = j;
            if (us.count(tmp)) ans.push_back(tmp);
        }
        tmp[i] = ori;
    }
    return ans;
}

int ans(string s, string t, unordered_set<string> &us) {
    if (us.count(s) == 0 || us.count(t) == 0) return 0;
    queue<pair<string, int>> q;
    q.push({s, 1});
    unordered_set<string> checked;
    checked.insert(s);
    while (!q.empty()) {
        auto [word, cnt] = q.front();
        q.pop();
        vector<string> tmp = get_neighbor(word, us);
        for (auto &data : tmp) {
            
            if (data == t) return cnt + 1;
            if (checked.count(data) == 0) {
                q.push({data, cnt + 1});
                checked.insert(data);
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        unordered_set<string> se;
        for (int i = 0; i < n; i++) {
            string tmp; cin >> tmp;
            se.insert(tmp);
        }
        cout << ans(s, t, se) << endl;
    }
}