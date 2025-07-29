#include <iostream>
#include <string>
using namespace std;


int main(){
    int n;
    cin >> n;

    int sum1 = 0, sum2= 0;
    string s;
    getline(cin,s);
    for(int i = 0; i < n; i++){
        getline(cin,s);

        if(s[5]- '0' == 1){
            sum1 += s[8] - '0';
        }else{
            sum2 += s[8] - '0';
        }
    }

    printf("%d x %d\n", sum1, sum2);
}
