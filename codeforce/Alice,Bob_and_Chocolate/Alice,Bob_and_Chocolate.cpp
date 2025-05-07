#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int>v;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int i = 0; 
    int j = v.size() - 1;
   
    int a = 0;
    int b = 0;
    while(i <= j){
        if(i+1 == j){
            a++;
            b++;
            break;
        }
        
        if(i == j){
            a++;
            break;
        }

        if(v[i] < v[j]){
            v[j] = v[j] - v[i];
            i++;
            a++;
        }else if(v[j] < v[i]){
            v[i] = v[i] - v[j];
            j--;
            b++;
        }else{
            i++;
            a++;
            j--;
            b++;
        }

    }

    cout << a << " " << b << " " << endl;
}
