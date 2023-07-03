#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string caracters;
    cin >> caracters;

    vector<int>nextIsEqual;

    int nowE = 0; 
    
    while(true){
        if(nowE == caracters.size() - 1){ //nao podemos olhar o prox do ultimo
            nextIsEqual.push_back(0);
            break;
        }

        if(caracters[nowE] == caracters[nowE + 1]){
            nextIsEqual.push_back(1);
        }else{
            nextIsEqual.push_back(0);
        }
        
        nowE++;
         
    }

    int queries;
    cin >> queries;

    while(queries--){ //lembrando que eu nao posso olhar o proximo do d, eu vou até d-1
        int e,d;
        cin >> e >> d;
        e--;
        d--;
        int sum = 0;
        int point = e;
        while(point != d){
            sum += nextIsEqual[point];
            point++;
        }

        cout << sum << endl;

    }

    return 0;
}