#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;
void gen (vector<int> &visited, vector<int> &a, int n){
    if (a.size() == n){
        for (int i = 0; i < n; i++){
            cout << a[i];
        }
        cout << " ";
    } else {
        for (int i = 1; i <= n; i++){
            if (visited[i] == 0){
                visited[i] = 1;
                a.push_back(i);
                gen(visited, a, n);
                a.pop_back();
                visited[i] = 0;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a;
        vector<int> visited(n + 1, 0);
        gen(visited, a, n);
        cout << endl;
    }
}