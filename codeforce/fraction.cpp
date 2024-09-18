#include <iostream>
#include <math.h>
using namespace std;

int mdc(int num, int deno){
    if(num%deno == 0){
        return deno;
    }else{
        return mdc(deno, num%deno);
    }
}


int main(){
    double n, nownum, nowdeno;
    double bestnum = 0, bestdeno = 1;
    cin >> n;

    bool temNum = false;

    for(int i = n - 1; i > 0; i--){ //cuidado com aqueles que não vao ter somas exatas  a n
        temNum = false;
        nowdeno = i;
        for(int j = nowdeno - 1; j > 0; j--){
            if(j + nowdeno == n){
                nownum = j;
                temNum = true;
                break;
            }            
        }
        if(((nownum / nowdeno) > (bestnum / bestdeno)) && temNum == true && mdc(nownum, nowdeno) == 1){
            bestnum = nownum;
            bestdeno = nowdeno;
        }
        
    }

    cout << bestnum << " " << bestdeno << endl;
    return 0;
}