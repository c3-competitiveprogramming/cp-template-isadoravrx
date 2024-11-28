#include<iostream>
#include<map>
using namespace std;

int main(){

    map<int,int> cartas;
    int n, x,maria=0,joao=0;
    scanf("%d",&n);
    for(int i=0;i<2;i++){
        scanf("%d",&x);
        if(x>=10){
            joao+=10;
            cartas[10]++;
        }
        else{
            joao+=x;
            cartas[x]++;
        }
    }

    for(int i=0;i<2;i++){
        scanf("%d",&x);
        if(x>=10){
            maria+=10;
            cartas[10]++;
        }
        else{
            maria+=x;
            cartas[x]++;
        }
    }

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x>=10){
            joao+=10;
            maria+=10;
            cartas[10]++;
        }
        else{
            maria+=x;
            joao+=x;
            cartas[x]++;
        }
    }
    

    int j=23-joao, m=23-maria, jj=-1, mm=-1;
    j++;

    if(j==10 && (cartas.find(10)==cartas.end() || cartas[10]<12)){
        jj=10;
    }
    if(j<10){
        for(int i=j;i<10;i++){
            if(cartas.find(i)==cartas.end() || cartas[i]<4){
                jj=i;
                break;
            }
        }
    }

    if(m==10 && (cartas.find(10)==cartas.end() || cartas[10]<12)){
        mm=10;
    }
    else if(m<10 && (cartas.find(m)==cartas.end() || cartas[m]<4)){
        mm=m;
    }

    if(mm==-1 && jj==-1){
        printf("-1\n");
    }
    else if(mm==-1 && maria+jj<24){
        printf("%d\n",jj);
    }
    else if(jj==-1){
        printf("%d\n",mm);
    }
    else if(jj<mm){
        printf("%d\n",jj);
    }
    else{
        printf("%d\n",mm);
    }

    return 0;
}