#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int visited[102][102];
int dx[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, -1, 1, 1};

bool pos_existe(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        return true;
    }
    return false;
}

void dfs(int cont, int x, int y, vector<vector<char> > &v) {
    visited[x][y] = cont;

    for (int i = 0; i < 8; i++) {
        if (visited[x+dx[i]][y+dy[i]] == 0 && pos_existe(x+dx[i], y+dy[i]) && v[x+dx[i]][y+dy[i]] == v[x][y]) {
            dfs(cont, x+dx[i], y+dy[i], v);
        }
    }
}

int main() {

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        vector<vector<char> > v(n, vector<char> (m));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                v[i][j] = c;
            }
        }

        int cont = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && v[i][j] != '*') {
                    dfs(cont, i, j, v);
                    cont++;
                }
            }
        }

        cout << cont-1 << endl;
    }

    return 0;
}