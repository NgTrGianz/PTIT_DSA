#include<bits/stdc++.h>
using namespace std;


int ans (int n){
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            if (i != n / i){
                cnt += abs(i % 2 - 1);
                cnt += abs((n/i) % 2 - 1);
            } else {
                cnt += abs(i % 2 - 1);
            }
        }
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << ans(n) << endl;
    }
}