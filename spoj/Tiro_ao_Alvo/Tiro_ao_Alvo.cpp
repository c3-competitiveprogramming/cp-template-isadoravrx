#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<double>r;

double bb(double value){
    long long ind = (lower_bound(r.begin(),r.end(),value)-r.begin());
    return (r.size() - ind);
}

int main(){
    double c,t;
    cin >> c >> t;
    
    double num;
    for(int i = 0; i < c ; i++){
        cin >> num;
        r.push_back(num);
    }
    long long cont = 0;
    double x,y;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
        double dist = sqrt((x*x) + (y*y));
        cont += bb(dist);
    }

    cout << cont << endl;
}
