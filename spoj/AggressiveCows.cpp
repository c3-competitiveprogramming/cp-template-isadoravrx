#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bestValue = 0;
int n; //quantidade de estabulos
int cows;
vector<int>points;

bool validate(int mid){
    int i = 0; // a primeira vaca sempre é colocada na primeira posicao
    int j = 1;
    int cont = 0;
    while(true){
        if(cont == cows - 1){ //pois a primeira sempre colocamos na primeira posicao. se ja bateu, é porque é  true
            return true;
        }
        if(j >= points.size()){ // significa que nao tem mais o que olhar
            break;
        }
        
        if(points[j] - points[i] >= mid){
            cont++;
            i = j;
            j = j + 1;
        }else{
            j++;
        }
    }

    return false;
    
}

int binarySearch(int low, int high){
    int mid = (low + high)/2;

    if(low > high){
        return bestValue;
    }

    if(validate(mid) == true){ //ou seja, se eu achei um numero bom, eu quero testar se valores maiores que ele tambem sao bons
        bestValue = mid; 
        return binarySearch(mid + 1, high);    
    }else{ // mas se meu valor não é bom, entao nenhum valor maior que ele tambem vai ser bom, entao tenho que pegar um numero menor
        return  binarySearch(low,mid - 1);
    }
}

int main(){
    int test;
    cin >> test;

    for(int i = 0; i < test; i++){
        
        cin >> n >> cows;
        points.clear();

        for(int i = 0; i < n; i++){
            int value;
            cin >> value;
            points.push_back(value);
        }

        sort(points.begin(),points.end());
        int low = 0; //menor distancia possivel entre duas vacas é 1, então o low é 1-1;
        int high = (points[points.size() - 1] - points[0]) + 1; //a maior distancia possivel entre duas vacas é o valor do último elemento, é a distancia entre o primeiro e o ultimo elemento, mais 1
        int answer = binarySearch(low,high);
        cout << answer << endl;
    }
}