#include <iostream>
#include <vector>
using namespace std;
vector<long>elements;

int menorIndexRepetidos(int mid){

    if(elements[mid-1] < elements[mid] || mid == 0){
        return mid;
    }

    return menorIndexRepetidos(mid - 1);
}

int binarysearch(long element){
    int low = 0;
    int high = elements.size() - 1;
    int mid = (low + high) / 2;
    while(low <= high){
        if(elements[mid] == element){ 
            if(mid == 0){ 
                return mid;
            }
            int menorIndexSeForrepetido = menorIndexRepetidos(mid);
            return menorIndexSeForrepetido;
        }

        if(element < elements[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }

    return -1;
}


int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    
    for(int i = 0; i < n; i++){
        long num;
        scanf("%ld", &num); 
        elements.push_back(num);
    }

    while(q--){
        long element;
        scanf("%ld", &element);
        int position = binarysearch(element);
        printf("%d\n",position);
    }

    return 0;
}