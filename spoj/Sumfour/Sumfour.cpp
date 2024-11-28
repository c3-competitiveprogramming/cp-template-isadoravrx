#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a[n],b[n],c[n],d[n];
    for(int i = 0; i < n; i++){
        int num1,num2,num3,num4;
        cin >> num1 >> num2 >> num3 >> num4;
        a[i] = num1;
        b[i] = num2;
        c[i] = num3;
        d[i] = num4;
    }
    
    vector<int> soma1(n*n),soma2(n*n);
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            soma1[index] = a[i] + b[j];
            soma2[index] = c[i] + d[j];
            index++;
        }
    }   
    int cont = 0;
    sort(soma2.begin(),soma2.end());
    pair<vector<int>::iterator,vector<int>::iterator>it;
    for(int i = 0; i < (n*n); i++){
        int mynum = soma1[i] * -1;
        it = equal_range(soma2.begin(),soma2.end(),mynum);
        cont += it.second - it.first; 
    }

    cout << cont << endl;
}
