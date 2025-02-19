#include<bits/stdc++.h>
using namespace std;
using str = string;
vector<str> name;
vector<int> tmp;
void in(){
    for (auto x : tmp){
        cout << name[x] << " ";
    }
    cout << endl;
}
int ok = 0;
int main(){
    int n, k;
    cin >> n >> k;
    set<string> se;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        se.insert(s);
    }
    for (auto data : se){
        name.push_back(data);
        cout << data << " ";
    }
    
    for (int i = 0; i < k; i++){
        tmp.push_back(i + 1);
    }
    while (!ok){
        in();
        int j = k - 1;
        while (j >= 0 && tmp[j] == (n - k + 1 + j)){
            --j;
        }
        if (j == -1){
            ok = 1;
            break;
        } else {
            tmp[j]++;
            for (int i = j + 1; i < k; i++){
                tmp[i] = tmp[i - 1] + 1;
            }
        }
    }
}  