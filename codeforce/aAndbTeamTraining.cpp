#include <iostream>
using namespace std;

int calculatinga(int exp, int nov){
    int cont = 0;
    while(true){
        exp = exp - 2;
        nov = nov--;
        if(exp < 0 || nov < 0){
            break;
        }

        cont++;
    }
    return cont;
}

int calculatingb(int exp, int nov){
    int cont = 0;
    while(true){
        exp--;
        nov = nov - 2;
        if(exp < 0 || nov < 0){
            break;
        }

        cont++;
    }
    return cont;
}

int main(){
    int exp, nov;
    cin >> exp >> nov;
    int qgruposa, qgruposb;

    qgruposa = calculatinga(exp,nov);
    qgruposb = calculatingb(exp,nov);

    if(qgruposa > qgruposb){
        cout << qgruposa << endl;
    }else{
        cout << qgruposb << endl;
    }

    return 0;
}