#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int tempn = n;

    //min
    int contmin= 0;
    tempn -= ((k1-1) * a1);
    tempn -=((k2-1) * a2);

    while(tempn > 0){
        contmin++;
        tempn--;
    }

    //max
    tempn = n;
    int contmax = 0;

    if(k1 < k2){
        contmax += min(tempn/k1,a1);
        tempn -= min(tempn/k1,a1) * k1;

        contmax += min(tempn/k2,a2);
        tempn -= min(tempn/k2,a2) * k2;
    }else{
        contmax += min(tempn/k2,a2);
        tempn -= min(tempn/k2,a2) * k2;

        contmax += min(tempn/k1,a1);
        tempn -= min(tempn/k1,a1) * k1;
    }
    cout << contmin << " " << contmax << endl;
}