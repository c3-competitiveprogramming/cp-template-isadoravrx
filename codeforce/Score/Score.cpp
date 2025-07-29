#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main(){
    int score;
    cin >> score;

    int v[] = {8,4,2,1};

    for(int i = 0; i < pow(2,4); i++){
        bitset<4>bt(i);
        int sum = 0;
        int quns = 0;

        for(int j = 0; j <  4; j++){
            if(bt[j] == 1){
                sum += v[j];
                quns++;
            }
        }   

        if(sum == score){
            cout << quns << endl;
            break;
        }
    }
}