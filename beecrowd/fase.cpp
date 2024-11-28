#include <iostream>
#include <vector>
using namespace std;
vector<int>scores;

void ordenacao(int competidores){
    for(int i = 1; i < competidores;i++){
        for(int j = i; j >= 1; j--){
            if(scores[j-1] < scores[j]){
                int temp = scores[j-1];
                scores[j-1] = scores[j];
                scores[j] = temp;
            }
        }
    }
}

int main(){
    int competidores,minclassificados,score;

    cin >> competidores >> minclassificados;
    int tempcomp = competidores;
    while(tempcomp--){
        cin >> score;
        scores.push_back(score);
    }
    ordenacao(competidores);

    int counter = 0;
    int lastScore = -1;
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] == lastScore){
            counter++;
            minclassificados--;
        }else if(minclassificados > 0){
            lastScore = scores[i];
            counter++;
            minclassificados--;
        }else{
            break;
        }
    }

    cout << counter << endl;

}