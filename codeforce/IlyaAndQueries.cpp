#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string caracters;
    cin >> caracters;

    vector<int>nextIsEqual;

    int i = 0; 
    int sum = 0;
    while(true){
        if(i == caracters.size() - 1){ //nao podemos olhar o prox do ultimo
            nextIsEqual.push_back(sum);
            break;
        }

        if(caracters[i] == caracters[i + 1]){
            nextIsEqual.push_back(sum);
            sum++;
        }else{
            nextIsEqual.push_back(sum);
        }
        
        i++;
        
    }

    int queries;
    cin >> queries;

    while(queries--){ //lembrando que eu nao posso olhar o proximo do d, eu vou até d-1
        int e,d;
        cin >> e >> d;
        e--;
        d--;
        
        int answer = nextIsEqual[d] - nextIsEqual[e];
        cout << answer << endl;

    }

    return 0;
}