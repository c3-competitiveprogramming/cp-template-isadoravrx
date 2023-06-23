#include <iostream>
#include <string>
using namespace std;

int main(){

    string caracters;
    int consultas;
    cin >> caracters >> consultas;
    int indexE, indexD;
    int nowE, nowD;
    int counter = 0;
    while(consultas--){
        cin >> indexE >> indexD;
        nowE = indexE - 1; //pois os index vao de 1 a n
        nowD = nowE + 1;
        counter = 0;
        while(true){
            if(nowD == indexD){
                break;
            }

            if(caracters[nowE] == caracters[nowD]){
                counter++;
            }
            nowE++;
            nowD++;
        }

        cout << counter << endl;

    }

    return 0;
}