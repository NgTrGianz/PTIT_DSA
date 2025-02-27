#include<bits/stdc++.h>
using namespace std;

bool chec(string s,string t){
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
        int check[n];
        int start,end;
        for(int i = 0; i < n ; i++){
            cin >> v[i];
            if(v[i] == s) {
                start = i;
                check[i] = 1;
            }
            else check[i] = 0;
            if(v[i] == t) end = i;
        }
        vector<int> ke[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(chec(v[i],v[j])){
                    ke[i].push_back(j);
                }
            }
        }
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x = q.front();
            if(x == end) break;
            q.pop();
            for(int u : ke[x]){
                if(check[u] == 0){
                    q.push(u);
                    check[u] = check[x] + 1;
                }
            }
        }
        cout << check[end] << endl;
    }
}
