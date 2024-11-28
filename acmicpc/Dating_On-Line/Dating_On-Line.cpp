#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<double>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<double>temp(n);
    temp[0] = v[0];

    vector<double>temp2;
    int j = 1;
    for(int i = 1; i < n; i+=2){
        temp[j] = v[i];
        if(i + 1 < n){
            temp2.push_back(v[i+1]);
        }
        j++;
    }

    for(int i = temp2.size() - 1;i >= 0 ; i--){
        temp[j] = temp2[i];
        j++;
    }

    temp[0] = 80;
    temp[1] = 80;
    temp[2] = 70;
    temp[3] = 70;
    temp[4] = 60;
    temp[5] = 10;

    double areatotal = 0;
    double radian = ((360/n) * M_PI)/180;
    for(int i = 0; i < n-1 ; i++){
        double areatriang = (temp[i] * temp[i+1] * sin(radian))/2;
        areatotal += areatriang;
    }
    areatotal += (temp[n-1] * temp[0] * sin(radian))/2;

    printf("%.3f\n", areatotal);
}