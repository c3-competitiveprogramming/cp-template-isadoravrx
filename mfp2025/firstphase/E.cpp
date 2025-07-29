#include <iostream>
#include <vector>
using namespace std;
int n,m;


bool ok(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }

    return false;
}
int main(){
    
    scanf("%d %d",&n, &m);

    vector<vector<int> >v(n, vector<int>(m));
    vector<vector<int> >modified(n, vector<int>(m));
    int dx[] = {0,-1};
    int dy[] = {-1,0};


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num;
            scanf("%d", &num);
 
            v[i][j] = num;

            int x = i;
            int y = j;

            for(int k = 0; k < 2; k++){
                int xi = x + dx[k];
                int yi = y + dy[k];
                if(ok(xi,yi) && v[x][y] == v[xi][yi]){
                    if(modified[xi][yi] == 1){
                        v[x][y]++;
                        modified[x][y]++;
                    }else{
                        v[xi][yi]++;
                        modified[xi][yi]++;
                    }
                    
                    
                }
            }
        

        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == m-1){
                printf("%d\n", v[i][j]);
            }else{
                printf("%d ", v[i][j]);
            }
        }
    }
    
}