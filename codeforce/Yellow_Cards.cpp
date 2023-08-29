#include <iostream>
using namespace std;
int a1,a2,k1,k2,n;
int elimina2(int tempn);
int minelimina1(int tempn);

int minelimina2(int tempn){
    int initialtempn = tempn;
    
    tempn -= (k2 - 1) * a2;
    
    if(tempn > 0 && initialtempn == n){
        tempn = minelimina1(tempn);
    }

    return tempn;
}

int minelimina1(int tempn){
    int initialtempn = tempn;
    
    tempn -= (k1 - 1) *  a1;

    if(tempn > 0 && initialtempn == n){
        tempn = minelimina2(tempn);
    }
    
    return tempn;
}

int elimina1(int tempn){
    int qmaxpos = tempn / k1;
    int sum = 0;
    if(qmaxpos > 0){
        if( a1 > qmaxpos){
            sum += qmaxpos;
        }else{
            sum += a1;
            if(tempn == n){ //significa que eu n eliminei ngm ainda
                tempn = tempn - (a1 * k1);
                sum += elimina2(tempn);
            }
        }
    }

    return sum;
}
int elimina2(int tempn){
    int qmaxpos = tempn / k2;
    int sum = 0;
    if(qmaxpos > 0){
        if( a2 > qmaxpos){
            sum += qmaxpos;
        }else{
            sum += a2;
            if(tempn == n){
                tempn = tempn - (a2 * k2);
                sum += elimina1(tempn);
            }
        }

    }

    return sum;
}

int main(){
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int maxjog = 0;

    if(k2 < k1){
        maxjog += elimina2(n);
    }else{
        maxjog += elimina1(n);
    }

    int tempnminjog = 0;
    int minjog = 0;

    if(k1 > k2){
        tempnminjog += minelimina1(n);
        if(tempnminjog > 0){
            minjog += elimina1(tempnminjog);
        }else{
            minjog = 0;
        }
    }else{
        tempnminjog += minelimina2(n);
        if(tempnminjog > 0){
            minjog += elimina2(tempnminjog);
        }else{
            minjog = 0;
        }
    }

    cout << minjog << " " <<  maxjog << endl;
}
