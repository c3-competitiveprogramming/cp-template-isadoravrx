#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int cont = 0;
    vector<pair<int,int> >trocas;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(v[j] > v[j + 1]){
                swap(v[j],v[j+1]);
                trocas.push_back(make_pair(j, j+1));
                cont++;
            }
        }
    }

    cout << cont << endl;
    for(int i = 0; i < trocas.size(); i++){
            cout << trocas[i].first << " " << trocas[i].second << endl;
    }


}




