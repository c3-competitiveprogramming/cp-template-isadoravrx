#include <iostream>
#include <vector>
using namespace std;
long long n, h;

int main(){
    cin >> n >> h;

    vector<long long>plan(1);
    vector<long long>qued(1);


    long long sum1 = 0;
    long long sum2 = 0;
    long long oldx;

    for(long long i = 0; i < n; i++){
        int num1,num2;
        cin >> num1 >> num2;
        sum1+=(num2 - num1);
        plan.push_back(sum1);

        if( i!= 0){
            sum2 += num1 - oldx;
            qued.push_back(sum2);
        }
        oldx = num2;
    }
    sum2 += 10e9 - oldx;
    qued.push_back(sum2);

    long long i = 0;
    long long j = 0;


    long long bestdist = 0;

    while(true){
        if(i == qued.size() || j == qued.size() - 1){
            bestdist = max(bestdist, (plan[j] - plan[i]) + (qued[j-1] - qued[i]) + (h - (qued[j-1] - qued[i])));
            break;
        }
        if(h > (qued[j] - qued[i])){
            j++;
        }else{
            bestdist = max(bestdist, (plan[j] - plan[i]) + (qued[j-1] - qued[i]) + (h - (qued[j-1] - qued[i])));
            i++;
        }
    }

    cout << bestdist << endl;

}