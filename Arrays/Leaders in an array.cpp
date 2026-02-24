#include <iostream>
#include <vector>
using namespace std;

// everything on right should be smaller

// ~ O(n2) , O(n)
void brute(int arr[], int n){
    vector<int> leaders;
    for (int i{} ; i<n ; ++i){
        bool leader=true;
        for (int j{i+1} ; j<n ; ++j){
            if (arr[i]<arr[j]) {
                leader=false;
                break;
            }
        }
        if (leader==true) leaders.emplace_back(arr[i]);
    }
    for (int it : leaders) cout << it << ' ';
}

void optimal(int arr[], int n){
    int max{arr[n-1]};
    vector<int> leaders{max};
    for (int i{n-2} ; i>=0 ; --i){
        if (arr[i]>max){
            leaders.emplace_back(arr[i]);
            max=arr[i];
        }
    }
    for (int it : leaders) cout << it << ' ';
}

int main() {
    int arr[]{10,22,12,3,0,6};
    brute(arr, size(arr));
    cout << endl;
    optimal(arr, size(arr));
    return 0;
}
