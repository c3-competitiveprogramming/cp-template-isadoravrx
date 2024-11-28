#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double a,b;
    cin >> a >> b;
    cout << fixed;
    cout << setprecision(2) << a/b << endl;
    return 0;
}