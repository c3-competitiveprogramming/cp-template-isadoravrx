#include <iostream>
#include <cstring>
using namespace std;

int mem[35];

long recursive(int n){
    if(n == 0){
        return 1;
    }

    if(mem[n] != -1){
        return mem[n];
    }
    long counter = 0;
    counter += recursive(n-1) + recursive(n - 2);

    return mem[n] = counter;
}

int main(){
    int n;
    cin >> n;

    memset(mem, -1, sizeof(mem));
    long answer = recursive(n);
    cout << answer << endl;
}
