#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int aero,voos;
    int test = 1;
    int cont = 0;
    while(true){
        cin >> aero >> voos;
        if(aero == 0 && voos == 0){
            break;
        }
        if(cont != 0){
            cout << endl;
        }
        int bestvalue = 0;
        vector<int>v;
        v.assign(aero,0);
        for(int i = 0 ; i < voos; i++){
            int x,y;
            cin >> x >> y;
            v[x - 1]++;
            if(v[x - 1] > bestvalue){
                bestvalue = v[x - 1];
            }
            v[y - 1]++;
            if(v[y - 1] > bestvalue){
                bestvalue = v[y-1];
            }
        }

        vector<int>answer;
        for(int i = 0; i < aero; i++){
            if(v[i] == bestvalue){
                answer.push_back(i + 1); //pois o valor do aeroporto comeca a ser contado de 1
            }
        }
        sort(answer.begin(), answer.end());

        printf("Teste %d\n",test);
        for(int i = 0; i < answer.size(); i++){
            if(i == answer.size() - 1){
                cout << answer[i] << endl;
            }else{
                cout << answer[i] << " ";
            }

        }

        test++;
        cont = 1 ;
    }

    return 0;
}