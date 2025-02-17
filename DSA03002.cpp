#include<bits/stdc++.h>
using namespace std;
using str = string;

int max_sum (str a, str b){
    for (auto &x : a){
        if (x == '5') x = '6';
    }
    for (auto &x : b){
        if (x == '5') x = '6';
    }
    return stoi(a) + stoi(b);
}

int min_sum (str a, str b){
    for (auto &x : a){
        if (x == '6') x = '5';
    }
    for (auto &x : b){
        if (x == '6') x = '5';
    }
    return stoi(a) + stoi(b);
}

int main(){
    str a, b;
    cin >> a >> b;
    cout << min_sum(a, b) << " " << max_sum(a, b);
}