#include <iostream>
using namespace std;

int max1s(int arr[], int n){
    int cntr{};
    int cnt{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]==1) {
            ++cnt;
            if (cntr<cnt) cntr=cnt;
        }
        else if (arr[i]==0) cnt=0;
    }
    return cntr;
}

int main() {
    int arr[]{1,1,0,1,1,1};
    int count{max1s(arr, size(arr))};
    cout << count;
    return 0;
}
