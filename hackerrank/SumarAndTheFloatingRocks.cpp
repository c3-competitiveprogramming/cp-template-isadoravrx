#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int, int);
int main(){
    int test,x1,y1,x2,y2,answer;
    cin >> test;
    while(test--){
        cin >> x1 >> y1 >> x2 >> y2;
        int sub1= abs(y2 - y1);
        int sub2 = abs(x2 - x1);
        answer = gcd(sub1,sub2) - 1;
        cout << answer << endl;
    }
    return 0;
}


int gcd( int subY, int subX){
    int resto;

    while(subX != 0){
        resto = subY % subX;
        subY = subX;
        subX = resto;
    }

    return subY;
}


