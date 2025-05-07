#include <iostream>
#include <vector>
#include <cstring>
#include <string>
typedef long long ll;
using namespace std;
vector<ll>ans;
string ansstring = "zzzzzzzzzzzz";
ll n,t;
vector<ll>primes;
string memo[65][18170];

string recursive(ll index, ll sum, ll peguei, vector<ll>v, string s){
    if(memo[index][sum] != " "){
        return memo[index][sum];
    }
    if(index > 62){
        return " ";
    }

    if(sum > n){
        return;
    }

    if(peguei > t){
        return;
    }

    if(sum == n && peguei == t){
        if(ansstring > s){
            ansstring = s;
            ans = v;
        }
        return;
    }

    string temp = s;
    if(primes[index] != 2){
        v.push_back(primes[index]);
        v.push_back(primes[index]);
       
        temp += to_string(primes[index]) + "+" + to_string(primes[index]) + "+"; 
        recursive(index+1, sum + (2 * primes[index]), peguei + 2,v, temp);

        v.pop_back();
        v.pop_back();
    }

    temp = s;
    temp += to_string(primes[index]) + "+";
    v.push_back(primes[index]);
    recursive(index+1, sum + primes[index], peguei + 1, v, temp);
    v.pop_back();        

    recursive(index+1, sum, peguei, v, s);
}

int main(){ 
    ll temp[] = {101,103,107,109,11,113,127,13,131,137,139,149,151,157,163,167,17,173,179,181,19,191,193,197,199,2,211,223,227,229,23,233,239,241,251,257,263,269,271,277,281,283,29,293,3,31,37,41,43,47,5,53,59,61,67,7,71,73,79,83,89,97};
    for(int i = 0; i < 62; i++){
        primes.push_back(temp[i]);
    }


    int test = 1;
    while(cin >> n >> t){
        if(n == 0 && t == 0){
            break;
        }

        memset(memo, ' ', sizeof(memo));
        vector<ll>v;
        recursive(0,0,0,v,"");

        printf("CASE %d:\n", test);
        
        if(ans.size() == 0){
            cout << "No Solution." << endl;
        }else{
            ansstring.erase(ansstring.end() -1);
            cout << ansstring << endl;
        }

        test++;
        ans.clear();
        ansstring = "zzzzzzzzzzzz";
    }
}