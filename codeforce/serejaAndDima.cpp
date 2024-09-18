#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    vector<int>nums;
    for(int i = 0; i < n; i++ ){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int s = 1; //indica quando e a vez de sereja
    int sereja = 0,dima = 0;
    vector<int>::iterator b;
    vector<int>:: iterator e;
    b = nums.begin();
    e = nums.end() - 1;

    while(b <= e){  
        if(s == 1){
            if(*b > *e){
                sereja += *b;
                b++; //vai para o prox elemento
            }else{
                sereja += *e;
                e--;
            }

            s = 0; 
        }else{
            if(*b > *e){
                dima += *b;
                b++;
            }else{
                dima += *e;
                e--;
            }

            s = 1;
        }
    }


    printf("%d %d\n", sereja, dima);
    return 0;
}
