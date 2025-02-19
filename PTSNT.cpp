#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

int intersection(str a){
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++){
        int j = i + 1;
        int cnt[256] = {0};
        cnt[a[i]]++;
        while (a[j] != a[i] && j < a.size()){
            if (cnt[a[j]] < 2) cnt[a[j]]++;
            if (cnt[a[j]] == 1){ 
                ++ans;
                cout << a[j] << endl;
            }
            if (cnt[a[j]] == 2) --ans;
            ++j;
        }
        cnt[a[j]]++;

    }
    return ans;
}
int main(){
    str s;
    cin >> s;
    cout << intersection(s) << endl;
}