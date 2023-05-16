#include <iostream>
#include <vector>
#include <utility> //pra usar o swap
#include <algorithm>
using namespace std;
vector<int>pages;
vector<int>auxpages;

vector<int>barreirasLeft;
vector<int>barreirasRight;
vector<int>indexs;

void ordenando( int limitLeft, int limitRight){ //mudar para quick sort, esse tá muito devagar
    if(limitLeft == limitRight){
        return;
    }
    sort(auxpages.begin() + limitLeft, auxpages.begin() + limitRight + 1);
}

int indexleftminimo(){
    
}

int main(){
    
    int qpaginas, qordenacao, limitLeft, limitRight, indeximportante;
    cin >> qpaginas >> qordenacao;
    int page;
    for(int i = 0; i < qpaginas; i++){
        cin >> page;
        pages.push_back(page);
    }

    int valorimportante , valorAgora;
    int tempqordenacao = qordenacao;
    while(tempqordenacao-){
        cin >> limitLeft >> limitRight >> indeximportante;
        limitLeft--;
        limitRight--;
        indeximportante--; //pois o index pra eles vai de 1 a n
        barreirasLeft.push_back(limitLeft);
        barreirasRight.push_back(limitRight);
        indexs.push_back(indeximportante);
    }

    int minLeft = indexleftminimo();
    int maxRight = indexrightmaximo();
    ordenando(minLeft,maxRight);


    for(int i = 0; i < qordenacao;i++){
        valorimportante = pages[indeximportante];
        valorAgora = auxpages[indeximportante];
        
        if(valorimportante == valorAgora){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }   
    }

    return 0;
}