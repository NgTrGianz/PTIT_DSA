#include<bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
int mod = 1e9 + 7;

void ans (int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int cnt = 0;
            while (n % i == 0){
                ++cnt;
                n /= i;
            }
            cout << i << "(" << cnt << ")" << " ";
        }
    }
    if (n > 1){
        cout << n << "(1)";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    int tc = 0;
    while (t--){
        ++tc;
        int n;
        cin >> n;  
        cout << "Test " << tc << ": ";
        ans(n);
    }
}