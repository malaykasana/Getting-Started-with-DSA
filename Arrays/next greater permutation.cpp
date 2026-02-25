#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Generate all permutations in sorted order
// Linear or binary search to find the given permutation
// return permutation at next index and if at last index return 1st permutation
void permute(int arr[], int arr2[][&n], int l, int r){

}

vector<int> brute (int arr[], int n){
    int total{};
    for (int i{1} ; i<=n ; ++i){
        total*=i;
    }
    int max{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]>max) max= arr[i];
    }
    ;
    int arr2[total][n];
    permute(arr, arr2, 0, n-1);
}

// use C++ STL
void better (int arr[], int n){
    next_permutation(arr, arr+n);
}

// write C++ STL next_permutation() code manually
void optimal(int arr[], int n){
    int index{-1};
    for (int i{n-2} ; i>=0 ; --i){
        if (arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if (index==-1){
        reverse(arr,arr+n);
    }
    for (int i{n-1} ; i>index ; --i){
        if (arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr+index+1,arr+n);
    for (int i{} ; i<n ; ++i){
        cout << arr[i] << ' ';
    }
}

int main() {
    int arr[]{1,3,2};
    vector<int> v{brute(arr, size(arr))};
    better (arr, size(arr));
    for (int it : arr) cout << it << ' ';
    cout << endl;
    optimal (arr, size(arr));
    return 0;
}
