#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>>pontos(2);
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        pontos[0].push_back(x);
        pontos[1].push_back(y);
    }

     float distancia,lowdistancia;
     int count = 0;

     for(int i = 0; i < n; i++ ){
         for(int j = 0; j < n; j++){
             if(i == j){//calcular a distancia do ponto até ele mesmo
                 continue;
             }

             float subx = pontos[0][j] - pontos[0][i];
             float suby = pontos[1][j] - pontos[1][i];
             if(count == 0){
                lowdistancia = sqrt(pow(subx,2) + (pow(suby,2)));
                 count++;
             }
            
             distancia = sqrt(pow(subx,2) + (pow(suby,2)));
                 if(distancia < lowdistancia){
                     lowdistancia = distancia;
                 }
         }
     }

     printf("%.3f\n", lowdistancia);
}
