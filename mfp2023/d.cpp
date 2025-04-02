#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    double M1, M2; 
    double X1, X2; 
    double F, G; 

    cin >> M1 >> M2;
    cin >> X1 >> X2;
    cin >> F;

    double daoquadrado = abs(X2 - X1) * abs(X2 - X1);
    G = (F * (daoquadrado)) / (M1 * M2);

    cout << setprecision(10) << fixed;

    cout << G << endl;

    return 0;

}
