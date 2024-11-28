#include <iostream>
using namespace std;

char whatismyposition(int xant, int yant,int xatual,int yatual){
    if(xatual == xant && yatual > yant){
        return 'n';
    }else if(xatual == xant && yatual < yant){
        return 's';
    }else if(xatual > xant && yatual == yant){
        return 'l';
    }else if(xatual < xant && yatual == yant){
        return 'o';
    }
}

int main(){
    int n,xant,yant,xatual,yatual;
    char myposition, lastposition;
    cin >> n;
    cin >> xant >> yant;
    n--;
    lastposition = 'n';
    int counter = 0;
    while(n--){
        cin >> xatual >> yatual;
        myposition = whatismyposition(xant,yant,xatual,yatual);
        if((lastposition == 'l' && myposition == 'n') || (lastposition == 'n' && myposition == 'o') || (lastposition == 'o' && myposition == 's') || (lastposition == 'n' && myposition == 'o') || (lastposition == 'o' && myposition == 's') || (lastposition == 's' && myposition == 'l') ){
            counter++;
        }
        lastposition = myposition;
        xant = xatual;
        yant = yatual;
    }

    cout << counter << endl;
}