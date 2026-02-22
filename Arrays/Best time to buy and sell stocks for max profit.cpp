#include <iostream>
using namespace std;

int maxprofit(int arr[], int n){
    int profit{}, gain{}, min_stock{arr[0]};
    for (int i{1} ; i<n ; ++i){
        gain = arr[i]-min_stock;
        if (gain > profit) profit = gain;
        if (arr[i]<min_stock) min_stock = arr[i];
    }
    return profit;
}

int main() {
    int arr[]{7,1,3,2,4,6,5};
    int profit{maxprofit(arr, size(arr))};
    cout << profit;
    return 0;
}
