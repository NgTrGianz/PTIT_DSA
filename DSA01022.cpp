#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> tmp(n);
        vector<int> a(n);
        for (int i = 0; i < a.size(); i++){
            cin >> a[i];
            tmp[i] = i + 1;
        }
        int cnt = 1;
        while (tmp != a){
            ++cnt;
            int j = n - 2;
            while (j >= 0 && tmp[j] > tmp[j + 1]){
                --j;
            }
            if (j == -1){
                break;
            } else {
                for (int k = n - 1; k > j; k--){
                    if (tmp[k] > tmp[j]){
                        swap(tmp[k], tmp[j]);
                        break;
                    }
                }
                sort(tmp.begin() + j + 1, tmp.end());
            }
        }
        cout << cnt << endl;
    }
}