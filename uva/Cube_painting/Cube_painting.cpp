#include<iostream>
#include<string>
using namespace std;

void printar(char cubo[]){
    for(int i=0;i<6;i++){
        cout<<cubo[i];
    }
    cout<<endl;
}

bool comparar(char cubo[6], char cubo1[6]){
    if(cubo[0]!=cubo1[0] || cubo[5]!=cubo1[5]){
        return false;
    }

    if(cubo[1]==cubo1[1] && cubo[2]==cubo1[2] && cubo[3]==cubo1[3] && cubo[4]==cubo1[4]){
        return true;
    }

    if(cubo[1]==cubo1[2] && cubo[2]==cubo1[3] && cubo[3]==cubo1[4] && cubo[4]==cubo1[1]){
        return true;
    }

    if(cubo[1]==cubo1[3] && cubo[2]==cubo1[4] && cubo[3]==cubo1[1] && cubo[4]==cubo1[2]){
        return true;
    }

    if(cubo[1]==cubo1[4] && cubo[2]==cubo1[1] && cubo[3]==cubo1[2] && cubo[4]==cubo1[3]){
        return true;
    }

    return false;
}

int main(){

    string s;

    while(cin>>s){

        char cubo[6]={s[0], s[1], s[2], s[3], s[4], s[5]};
        
        char cubo1[6]={s[1+5], s[5+5], s[4+5], s[2+5], s[3+5], s[6+5]};
        if(comparar(cubo, cubo1)){
            cout<<"TRUE"<<endl;
            continue;
        }

        char cubo2[6]={s[2+5], s[1+5], s[4+5], s[6+5], s[3+5], s[5+5]};
        if(comparar(cubo, cubo2)){
            cout<<"TRUE"<<endl;
            continue;
        }

        char cubo3[6]={s[3+5], s[1+5], s[2+5], s[6+5], s[5+5], s[4+5]};
        if(comparar(cubo, cubo3)){
            cout<<"TRUE"<<endl;
            continue;
        }

        printar(cubo);
        printar(cubo1);

        char cubo4[6]={s[4+5], s[1+5], s[5+5], s[6+5], s[2+5], s[3+5]};
        if(comparar(cubo, cubo4)){
            cout<<"TRUE"<<endl;
            continue;
        }

        char cubo5[6]={s[5+5], s[1+5], s[3+5], s[6+5], s[4+5], s[2+5]};
        if(comparar(cubo, cubo5)){
            cout<<"TRUE"<<endl;
            continue;
        }

        char cubo6[6]={s[6+5], s[2+5], s[4+5], s[5+5], s[3+5], s[1+5]};
        if(comparar(cubo, cubo6)){
            cout<<"TRUE"<<endl;
            continue;
        }

        cout<<"FALSE"<<endl;

    }

    return 0;
}