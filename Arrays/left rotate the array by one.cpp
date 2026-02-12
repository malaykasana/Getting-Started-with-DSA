#include <iostream>
using namespace std;

// optimal method
void shift(int arr[], int n){
    int var{arr[0]};
    for (int i{1} ; i<n ; ++i){
        arr[i-1]=arr[i];
    }
    arr[n-1]=var;
}

int main() {
    int arr[]{1,2,3,4,5};
    int size{sizeof(arr)/sizeof(arr[0])};
    // brute method is to create a temporary array and add all the elements from index 1
    // then at the last index n-1 add the first element of the original array arr[0].
    shift(arr, size);
    for (int it : arr){
        cout << it << ' ';
    }
    return 0;
}
