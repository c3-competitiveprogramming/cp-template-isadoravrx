#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int> >adj(n + 2);
    vector<int>ins;
    for(int i = 0; i < 2*n ; i++){
        string s;
        int num;
        cin >> s >> num;
        if(s == "in"){
            if(ins.size() > 0){
                adj[ins[ins.size()-1]].push_back(num);
            }
            ins.push_back(num);
        }else{ 
            ins.pop_back();
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            cout << i << " " << adj[i][j] << endl;
        }
    }

}