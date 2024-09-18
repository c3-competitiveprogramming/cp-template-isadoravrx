#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int test;
    cin >> test;
    int t = 1;
    while(test--){
        long long inf, sup;
        cin >> inf >> sup;

        long long n = inf;
        long long cont = 0;
        vector<long long>v;
        while(n <= sup){
            long long newn = pow(n,2);
            string s = to_string(newn);
            string s1 = "", s2 = "";

            for(int i = 0; i < s.size(); i++){
                if(s.size() % 2 == 0){
                    if(i < (s.size() /2)){
                        s1 += s[i];
                    }else{
                        s2 += s[i];
                    }
                }else{
                    if(i < (s.size() /2)){
                        s1 += s[i];
                    }else{
                        s2 += s[i];
                    }
                }
            }


            bool difzero = false;
            int indexfzero = 0;
            for(int i = s1.size() - 1; i >= 0; i-- ){
                if(s1[i] != '0'){
                    if(difzero == false){
                        indexfzero = i + 1;
                    }
                    difzero = true;
                }

            }
            
            string aux = "";
            for(int i = 0; i < s1.size(); i++){
                aux += s1[i];
                if(i >= indexfzero -1){
                    if(stoi(aux) + stoi(s2) == n){
                        s1 = aux;
                        break;
                    }
                }
            }
            if(s1 != "" && s2 != "" && stoi(s1) + stoi(s2) == n && stoi(s1) != 0 && stoi(s2) != 0){
                v.push_back(n);
            }
            n++;
        }

        cout << "case #" << t << endl;
        if(v.size() == 0){
            cout << "no kaprekar numbers" << endl;
        }else{
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << endl;
            }
        }

        if(test != 0){
            cout << endl;
        }
        t++;
    }
}
