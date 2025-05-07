#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        double l;
        cin >> l;


        double width = (6 * l)/10;
        double radius = l/5;

        double area_circulo = M_PI * (radius * radius);
        double area_quadrado = (l*width) - area_circulo;

        printf("%.2lf %.2lf\n", area_circulo, area_quadrado);
    }

}