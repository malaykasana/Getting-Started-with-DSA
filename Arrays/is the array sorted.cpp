#include <iostream>
using namespace std;

bool sorted(int arr[], int n){
    for (int i{1} ; i<n ; ++i){
        if(arr[i]<arr[i-1]) return false;
    }
    return true;
}

int main() {
    int arr[]{1,2,2,3,4,5};
    int size{sizeof(arr)/sizeof(arr[0])};
    bool b{sorted(arr,size)};
    if (b) cout << "The array is sorted";
    else cout << "The array is not sorted";
    return 0;
}
