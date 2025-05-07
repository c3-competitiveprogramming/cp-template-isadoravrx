#include <iostream>
#include <vector>
#include <utility> //pra usar o swap
#include <algorithm>
using namespace std;
vector<int>pages;

int qmenoresOrdenado(int limitLeft,int limitRight, int indeximportante){
    int counter = 0;
    for(int i = limitLeft; i <= limitRight; i++){
        if(pages[i] < pages[indeximportante]){
            counter++;
        }
    }

    return counter;
}

int main(){
    
    int qpaginas, qordenacao, limitLeft, limitRight, indeximportante;
    cin >> qpaginas >> qordenacao;
    int page;
    for(int i = 0; i < qpaginas; i++){
        cin >> page;
        pages.push_back(page);
    }
    int posicaoNova;
    int qelementosantesleft, qelementosMenoresEntreFronteiras;
   
    while(qordenacao--){
        cin >> limitLeft >> limitRight >> indeximportante;
        limitLeft--;
        limitRight--;
        indeximportante--; //pois o index pra eles vai de 1 a n
        if(indeximportante == 0){
            qelementosantesleft = 0;
        }else{
            qelementosantesleft = limitLeft;
        } 
        qelementosMenoresEntreFronteiras = qmenoresOrdenado(limitLeft,limitRight,indeximportante);
        posicaoNova = qelementosantesleft + qelementosMenoresEntreFronteiras;
        if(posicaoNova == indeximportante){ //ou seja, ele nao mudou de lugar
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}