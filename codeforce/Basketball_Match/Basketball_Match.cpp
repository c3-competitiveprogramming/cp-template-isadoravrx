#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    int time1 = 0;
    int time2 = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        int ntime;
        cin >> ntime;

        string pontstring;
        cin >> pontstring;

        int pont = pontstring[1] - '0';


        if(ntime == 1){
            time1 += pont;
        }else{
            time2 += pont;
        }
    }

    printf("%d x %d\n", time1,time2);
}