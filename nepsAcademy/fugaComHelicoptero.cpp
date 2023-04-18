#include <iostream>
using namespace std;

int main(){
    int h,p,f,d;
    cin >> h >> p >> f >> d;
    int distanciaf;
    int distanciap;
    if(d == -1){
        distanciaf = f - h;
        distanciap = p - h;
       
    }else{
        distanciaf = h - f;
        distanciap = h - p;
        
    }

    if(distanciaf < distanciap){
            cout << "S" << endl;
    }else{
            cout << "N" << endl;
    }

}