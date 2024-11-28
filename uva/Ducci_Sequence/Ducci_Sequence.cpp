#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool compare(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if(arr[i] != 0){
            return false;
        }
    }
    return true;
}

void ducci(vector<int> &arr, int n) {
    vector<int> temp = arr;
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            arr[i] = abs(temp[i] - temp[0]);
        } else {
            arr[i] = abs(temp[i] - temp[i+1]);
        }
    }
}

int main() {
    int t, n, a;
    cin >> t;

    while (t--) {
        vector<int> arr;
        map<vector<int>,int>tuples;

        cin >> n;
        vector<int> zeros (n);

        for (int i = 0; i < n; i++) {
            cin >> a;
            arr.push_back(a);
        }

        
        while (true) {
            ducci(arr, n);
            if (compare(arr)) {
                cout << "ZERO" << endl;
                break;
            } else if (tuples.find(arr) != tuples.end()) {
                cout << "LOOP" << endl;
                break;
            } else {
                tuples[arr]++;
            }
        }
    }

    return 0;
}