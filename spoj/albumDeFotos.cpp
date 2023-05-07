#include <iostream>
using namespace std;

int main(){
    int xpg,ypg;
    int x1,y1,x2,y2;
    cin >> xpg >> ypg >> x1 >> y1 >> x2 >> y2;
    int areapag = xpg * ypg;
    int areafotos = (x1 * y1) + (x2 * y2);
    if(areapag >= areafotos && (x1 + x2 <= xpg && y1 + y2 <= ypg)){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}