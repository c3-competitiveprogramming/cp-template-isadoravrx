#include <iostream>
using namespace std;

int main(){
    int x,y,num = 1, qporlinha = 0;
    cin >> x >> y;
    while(true){
        if(num > y){
            break;
        }

        if(qporlinha == x - 1){
            cout << num << endl; 
            qporlinha = 0;
        }else{
            cout << num << " ";
            qporlinha++;
        }

        num++;
    }
    return 0;
}