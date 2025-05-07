#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double pi = acos(-1);
int main(){

    double d,m;
    cin >> d >> m;

    double x = d/sin((45 * pi) / 180);
    double y = d;

    double qretas = m/x;
    int qretasint = m/x;

    cout << setprecision(10) << fixed;
    if(qretas == qretasint){
        if(qretasint % 2 == 0){
            cout << qretasint*y << " " << 0 << endl;
        }else{
            cout << qretasint*y << " " << d << endl;
        }
    }else{
        double qandeiultimareta = (m - (x*qretasint));

        double xestou, yestou;
        double xvou, yvou;
        xestou = (double)qretasint * y;
        xvou = xestou + y;

        if(qretasint % 2 == 0){
            yestou = 0;
            yvou = d;
            
        }else{
            yestou = d;
            yvou = 0;
        }   

        double fator = qandeiultimareta / x;
        double xfinal = xestou + fator * (xvou - xestou);
        double yfinal = yestou + fator * (yvou - yestou);
        
        cout << xfinal << " " << yfinal << endl;
    }
    
}