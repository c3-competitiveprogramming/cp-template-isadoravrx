#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>>tv;
int main(){
    int m,n;
    int test = 1;
    bool b = false;
    while(true){
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0){
            break;
        }

        if(b == true){
            cout << endl;
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

        int x = 0, y = 0;
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
            c = (n - 1) - ((x -1) % n);
        }else if(x < 0){
            c = abs(x) % n;
        }

        if(y > 0){
            l = y % m;
        }else if(y < 0){
            l = (m - 1) - ((abs(y) -1) % m);
        }
    
        int i = l;
        int j = c;
        
        bool cont = false;
        printf("Teste %d\n", test);
        while(true){
            int index = j;
            if(i == m){
                i = 0;
            }

            if(i == l && cont == true){
                break;
            }
            for(int k = 0; k < n; k++){
                if(index == n){
                    index = 0;
                }
                if(k == n - 1){
                    cout << tv[i][index] << endl;
                }else{
                    cout << tv[i][index] << " ";
                }
                index++;
            }

            i++;
            cont = true;
        }

        test++;
        b = true;
    }
}
