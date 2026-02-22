#include <iostream>
using namespace std;

int brute(int arr[], int n){
    int max_sum{};
    int Sum{};
    for (int i{} ; i<n ; ++i){
        for (int j{i} ; j<n ; ++j){
            Sum = 0;
            for (int k{i} ; k<j ; ++k){
                Sum += arr[k];
            }
            if (Sum > max_sum) max_sum = Sum;
        }
    }
    return max_sum;
}

int better(int arr[], int n){
    int max_sum{};
    int Sum{};
    for (int i{} ; i<n ; ++i){
        Sum=0;
        for (int j{i} ; j<n ; ++j){
            Sum += arr[j];
            if (Sum > max_sum) max_sum = Sum;
        }
    }
    return max_sum;
}

// Kadane's algo
int optimal(int arr[], int n){
    int max_sum{};
    int sm{};
    int ans_start{}, ans_end{}, start{};
    for (int i{}; i<n ; ++i){
        if (sm < 0) {
            sm=0;
            start=i;
        }
        sm += arr[i];
        if (sm > max_sum) {
            max_sum = sm;
            ans_start=start;
            ans_end=i;
        }
    }
    cout << "Index of Subarray : (" << ans_start << ',' << ans_end << ")\n";
    return max_sum;
}

int main() {
    int arr[]{1,-2,-3,4,-1,-2,1,5,-3};
    // int max_subarray_sum{brute(arr, size(arr))};
    // int max_subarray_sum{better(arr, size(arr))};
    int max_subarray_sum{optimal(arr, size(arr))};
    cout << "Sum of elements of Subarray : " << max_subarray_sum;
    return 0;
}
