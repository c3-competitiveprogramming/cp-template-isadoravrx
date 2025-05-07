#include <iostream>
using namespace std;

int recursao(int n){
    if(n <= 100){
        return recursao(recursao(n + 11));
    }else{
        return n - 10;
    }

}

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        int result = recursao(n);
        printf("f91(%d) = %d\n",n,result);
    }
}
