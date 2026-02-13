#include <iostream>
#include <vector>
using namespace std;

// without help
void brute(int arr[], int n){
    vector<int> temp;
    for (int i{0} ; i<n ; ++i){
        if (arr[i] != 0) temp.emplace_back(arr[i]);
    }
    for (int j{0} ; j<temp.size() ; ++j){
        arr[j]=temp[j];
    }
    for (int j{temp.size()} ; j<n ; ++j){
        arr[j]=0;
    }
    return;
}

// Done without any help but still need to understand it more
void better(int arr[], int n){
    int i{0};
    for (int j{1} ; j<n ; ++j){
        if (arr[i] == 0){
            if (arr[j] != 0){
                swap(arr[i], arr[j]);
                ++i;
            }
        } else ++i;
    }
}

int main() {
    int arr[]{1,2,0,0,2,1,0,3,0,4};
    int n{sizeof(arr)/sizeof(arr[0])};
    // brute(arr, n);
    better(arr, n);
    for (int it : arr) cout << it << ' ';
    return 0;
}
