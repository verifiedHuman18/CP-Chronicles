
/*
TC -O(N)
SC -O(1)

*/


#include <bits/stdc++.h>
using namespace std;

string s;
bool visited[7][7];
int ans;

bool inside(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

void dfs(int x, int y, int step) {
    if (x == 6 && y == 0) {
        if (step == 48) ans++;
        return;
    }

    if (step == 48) return;

    if ((!inside(x-1,y) || visited[x-1][y]) &&
        (!inside(x+1,y) || visited[x+1][y])) {
        if (inside(x,y-1) && !visited[x][y-1] &&
            inside(x,y+1) && !visited[x][y+1])
            return;
    }

    if ((!inside(x,y-1) || visited[x][y-1]) &&
        (!inside(x,y+1) || visited[x][y+1])) {
        if (inside(x-1,y) && !visited[x-1][y] &&
            inside(x+1,y) && !visited[x+1][y])
            return;
    }

    char c = s[step];

    if (c == '?' || c == 'U') {
        int nx = x - 1, ny = y;
        if (inside(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, step + 1);
            visited[nx][ny] = false;
        }
    }

    if (c == '?' || c == 'D') {
        int nx = x + 1, ny = y;
        if (inside(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, step + 1);
            visited[nx][ny] = false;
        }
    }

    if (c == '?' || c == 'L') {
        int nx = x, ny = y - 1;
        if (inside(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, step + 1);
            visited[nx][ny] = false;
        }
    }

    if (c == '?' || c == 'R') {
        int nx = x, ny = y + 1;
        if (inside(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, step + 1);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    cin >> s;
    visited[0][0] = true;
    dfs(0, 0, 0);
    cout << ans;
}
