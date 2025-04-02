#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const double pi = acos(-1);

int main(){ _
    int angle, n;
    cin >> angle >> n;

   vector<pair<double,double> >sombras;
    double tanangle = tan(((double)angle*pi)/180);
    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        double csombra = (double)h/tanangle;
        sombras.push_back(make_pair((double)x,(double)x+csombra));
    }   

    sort(sombras.begin(), sombras.end());
    double sum = 0, maxfim;
    bool b = true;
    for(auto it : sombras){
        double ini = it.first;
        double fim = it.second;
        if(maxfim <fim){
            sum += fim - max(ini, maxfim);
        }
        maxfim = max(maxfim, fim);
    }

    cout << fixed << setprecision(15) << sum << endl;
}
