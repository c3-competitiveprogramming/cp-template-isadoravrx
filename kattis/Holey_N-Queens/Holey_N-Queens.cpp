#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n,m;
int cont = 0;
map<int,int>l;
map<int,int>cp;
map<int,int>cs;

void rec(long long col, vector<vector<int> > &v){

    if(col == n){
        cont++;
        return;
    }
    for(long long i = 0; i < n; i++){
        if(l[i] != 1 && cp[i-col] != 1 && cs[i+col] != 1 && v[i][col] == 0){
            l[i] = 1;
            cp[i-col] = 1;
            cs[i+col] = 1;

            rec(col+1,v);

            l[i] = 0;
            cp[i-col] = 0;
            cs[i+col] = 0;
        }
    }
}

int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }

        cont = 0;
        vector<vector<int> >v(n, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            v[x][y] = 1;
        }

        rec(0,v);

        cout << cont << endl;
    }
}
