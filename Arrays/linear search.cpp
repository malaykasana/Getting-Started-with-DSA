#include <iostream>
using namespace std;

int ls(int arr[], int n, int num){
    for (int i{0} ; i<n ; ++i){
        if (arr[i] == num) return i;
    }
    return -1;
}

int main() {
    int arr[]{3,2,4,6,4,1,7};
    int n{size(arr)};
    int num{1};
    int x{ls(arr, n, num)};
    cout << x;
    return 0;
}
