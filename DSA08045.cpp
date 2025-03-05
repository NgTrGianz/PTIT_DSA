#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
struct fence{
    int x1, x2, y1, y2;
};
struct cow{
    int x, y;
};
char grid[2000][2000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int col_bound = 0;
int row_bound = 0;
void init_grid(fence Fences[], cow Cows[], int n, int k){
    int idx = 2;
    map<int, int> standard_X;
    
    for (int i = 0; i < n; i++){
        standard_X[Fences[i].x1] = standard_X[Fences[i].x2] = 1;
    }
    for (int i = 0; i < k; i++){
        standard_X[Cows[i].x] = 1;
    }
    for (auto &[data, index] : standard_X){
        index = idx;
        idx += 2;
    }

    col_bound = idx + 10;

    idx = 2;
    map<int, int> standard_Y;
    for (int i = 0; i < n; i++){
        standard_Y[Fences[i].y1] = standard_Y[Fences[i].y2] = 1;
    }
    for (int i = 0; i < k; i++){
        standard_Y[Cows[i].y] = 1;
    }
    for (auto &[data, index] : standard_Y){
        index = idx;
        idx += 2;
    }
    row_bound = idx + 10;


    for (int i = 0; i < n; i++){
        Fences[i].x1 = standard_X[Fences[i].x1];
        Fences[i].x2 = standard_X[Fences[i].x2];
        Fences[i].y1 = standard_Y[Fences[i].y1];
        Fences[i].y2 = standard_Y[Fences[i].y2];
    }
    for (int i = 0; i < k; i++){
        Cows[i].x = standard_X[Cows[i].x];
        Cows[i].y = standard_Y[Cows[i].y];
    }

    for (int i = 0; i < row_bound; i++){
        for (int j = 0; j < col_bound; j++){
            grid[i][j] = '.';
        }
    }

    for (int i = 0; i < k; i++){
        grid[Cows[i].y][Cows[i].x] = 'C';
    }
    for (int i = 0; i < n; i++){
        if (Fences[i].x1 == Fences[i].x2){
            int start = min(Fences[i].y1, Fences[i].y2);
            int end = max(Fences[i].y1, Fences[i].y2);
            for (int j = start; j <= end; j++){
                grid[j][Fences[i].x1] = 'X';
            }
        }
        if (Fences[i].y1 == Fences[i].y2){
            int start = min(Fences[i].x1, Fences[i].x2);
            int end = max(Fences[i].x1, Fences[i].x2);
            for (int j = start; j <= end; j++){
                grid[Fences[i].y1][j] = 'X';
            }
        }
    }
    // for (int i = 0; i <= row_bound; i++){
    //     for (int j = 0; j <= col_bound; j++){
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    // 
    // for (int i = 0; i < n; i++){
    //     cout << Fences[i].x1 << " " << Fences[i].y1 << " " << Fences[i].x2 << " " << Fences[i].y2 << endl;
    // }
    // for (auto [data, id] : standard_X){
    //     cout << data << " " << id << endl;
    // }
}

int BFS (int x, int y){
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()){
        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (0 <= nx && nx < row_bound && 0 <= ny && ny < col_bound && grid[nx][ny] != 'X'){
                if (grid[nx][ny] == 'C'){
                    ++cnt;
                }
                q.push({nx, ny});
                grid[nx][ny] = 'X';
            }
        }
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        fence Fences[n];
        cow Cows[k];
        for (int i = 0; i < n; i++){
            cin >> Fences[i].x1 >> Fences[i].y1 >> Fences[i].x2 >> Fences[i].y2;
        }
        for (int i = 0; i < k; i++){
            cin >> Cows[i].x >> Cows[i].y;
        }
        init_grid(Fences, Cows, n, k);
        int ans = 0;
        for (int i = 0; i < k; i++){
            if (grid[Cows[i].y][Cows[i].x] == 'C'){
                int cnt = BFS(Cows[i].y, Cows[i].x);
                ans = max(ans, cnt);
            }
        }
        cout << ans << endl;
    }
}