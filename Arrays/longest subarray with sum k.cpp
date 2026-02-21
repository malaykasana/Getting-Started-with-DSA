#include <iostream>
#include <unordered_map>
using namespace std;

// O(n3), O(1)
int brute1(int arr[], int n, int k){
    int len{};
    for (int start{} ; start<n ; ++start){
        for (int end{start} ; end<n ; ++end){
            int llen{};
            int sum{};
            for (int h{start} ; h<=end ; ++h){
                sum += arr[h];
            }
            if (sum==k){
                if (end-start+1>len){
                    len=end-start+1;
                }
            }
        }
    }
    return len;
}

// o(n2), o(1)
int brute2(int arr[], int n, int k){
    int len{};
    for (int start{} ; start<n ; ++start){
        int sum{};
        for (int end{start} ; end<n ; ++end){
            sum += arr[end];
            if (sum==k){
                if (len<end-start+1) len=end-start+1;
            }
        }
    }
    return len;
}

// O(n), O(n)
// O(nlogn) if we use map instead of unordered_map
int better(int arr[], int n, int k){
    unordered_map<int,int> presumMap;
    int len{}, presum{};
    for (int i{} ; i<n ; ++i){
        presum += arr[i];
        if (presum==k) len=i+1;
        int rem{presum-k};
        if (presumMap.find(rem) != presumMap.end()){
            if (len < i-presumMap[rem]) len = i-presumMap[rem];
        }
        if (presumMap.find(presum) == presumMap.end()) presumMap[presum]=i;
    }
    return len;
}

// the above methods work for both +ve and -ve numbers 
// but if we have only +ve numbers then we can use the below method which is more efficient than the above methods.

// O(n), O(1)
int optimal(int arr[], int n, int k){
    int i{}, j{}, len{}, sum{};
    while (j<n){
        while (i<=j && sum>k){
            sum -= arr[i];
            ++i;
        }
        sum += arr[j];
        if (sum==k){
            if (len<j-i+1) len= j-i+1;
        }
        ++j;
    }
    return len;
}

int main() {
    int arr[]{10, 5, 2, 7, 1, 9};
    int k{15};
    // int len{brute1(arr, size(arr), k)};
    // int len{brute2(arr, size(arr), k)};
    // int len{better(arr, size(arr), k)};
    int len{optimal(arr, size(arr), k)};
    cout << len;
    return 0;
}
