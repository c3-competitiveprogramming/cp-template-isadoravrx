#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>>tv;
int main(){
    int m,n;
    while(true){
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0){
            break;
        }
        tv.clear();
        tv.resize(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int num;
                scanf("%d", &num);
                tv[i].push_back(num);
            }
        }

        int x, y;
        int tempx,tempy;
        while(true){
            scanf("%d %d", &tempx,&tempy);
            if(tempx == 0 && tempy == 0){
                break;
            }

            x += tempx;
            y += tempy;
        }
        
        int l = 0, c = 0;
        if(x > 0){
            c = ((n - 1) - (x -1)) % n;
        }else if(x < 0){
            c = abs(x) % n;
        }

        if(y > 0){
            l = y % m;
        }else if(y < 0){
            l = ((m - 1) - (abs(y) -1)) % m;
        }
    
        int i = l;
        int j = c;

        while(true){
            cout << tv[i][j] << " ";
            j++;
            while(true){
                if(j == n){
                    j = 0;
                }

            }
            
            i++;
            if(i == m){
                i = 0;
            }
            if(i == l){
                break;
            }
        }
    }
}
