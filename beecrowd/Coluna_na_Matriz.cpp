#include <iostream>
using namespace std;

int main(){
    int c;
    cin >> c;
    char op;
    cin >> op;


    double sum = 0;

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            double num;
            cin >> num;
            if(j == c){
                sum += num;
            }            
        }
    }


    if(op == 'S'){
        printf("%.1f\n",sum);
    }else{
        printf("%.1f\n",sum/12);
    }
}
