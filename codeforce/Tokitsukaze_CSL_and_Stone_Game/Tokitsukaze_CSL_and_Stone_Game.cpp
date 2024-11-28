#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;

int repetidos(int i){
    int index = i + 1;
    int cont = 1;
    while(index < v.size() && v[index] == v[i]){
        cont++;
        index++;
    }

    return cont;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    v.push_back(-1);
    sort(v.begin(),v.end());

    int i = 0;
    
    int gruporep = 0;
    for(int i = 0; i < n; i++){
        if(gruporep > 1){
            cout << "cslnb" << endl;
            return 0;
        }
        int qrepetidos = repetidos(i);
        if(qrepetidos == 2){
            if(i != 0 && v[i-1] == v[i] - 1){
                cout << "cslnb" << endl;
                return 0;
            }
            gruporep++;
        } 
        if(qrepetidos > 2){
            cout << "cslnb" << endl;
            return 0;
        }
    }
    
    v.erase(v.begin());
    long long sum = 0;
    while(i < v.size()){
        if(v[i] - i > 0){
            sum += v[i] - i;
        }
        i++;
    }

    if(sum % 2 == 0){
        cout << "cslnb" << endl;
    }else{
        cout << "sjfnb" << endl;
    }
}
