#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculate(double j, double k){
    double ans = ((k*j)/(j-k));

    if(int(ans) == ans){
        return ans;
    }

    return -1;
}


int main(){
    double k;

    while(cin >> k){
        double j = k*2;

        vector<pair<double,double> >v;
        while(j > k){
            double result = calculate(j,k);
            if(result != -1){
                v.push_back(make_pair(result,j));
            }
            j--;
        }

        cout << v.size() << endl;
        for(double i = v.size() -1 ; i >= 0; i--){
            printf("1/%.0f = 1/%.0f + 1/%.0f\n", k, v[i].first, v[i].second);
        }

    }
}