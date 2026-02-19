#include <iostream>
#include <unordered_set>
using namespace std;

int brute(int arr[], int n){
    // Brute
    unordered_set<int> set{};
    for (int i{0} ; i<n ; ++i){
        set.insert(arr[i]);
    }
    int j{0};
    for (int value : set){
        arr[j++] = value;
    }
    return j;
}

int brute2(int arr[], int n){
    unordered_set<int> set;
    int j = 0;
    for (int i{0} ; i<n ; ++i){
        if (set.find(arr[i]) == set.end()){
            set.insert(arr[i]);
            arr[j++]=arr[i];
        }
    }
    return j;
}

int optimal(int arr[], int n){
    int i{0};
    for (int j{1} ; j<n ; ++j){
        if (arr[i] != arr[j]) {
            arr[++i]=arr[j];
        }
    }
    return i+1;
}

int main() {
    int arr[]{1,1,2,2,2,3,3};
    int size{sizeof(arr)/sizeof(arr[0])};
    // int sizeset=brute(arr,size);
    // int sizeset{brute2(arr, size)};
    int sizeset{optimal(arr, size)};
    for (int i{0} ; i<sizeset ; ++i) cout << arr[i] << ' ';
    return 0;
}
