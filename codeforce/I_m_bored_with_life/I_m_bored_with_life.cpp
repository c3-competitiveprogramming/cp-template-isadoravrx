#include <iostream>
#include <algorithm>
using namespace std;

long long factorial(long long x){
    if(x == 1){
        return 1;
    }

    return x * factorial(x-1);
}

int main(){
    long long a,b;
    cin >> a >> b;

    cout << factorial(min(a,b)) << endl;
    
}
