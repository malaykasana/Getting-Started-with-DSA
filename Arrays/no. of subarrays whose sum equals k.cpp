#include <iostream>
#include <unordered_map>
using namespace std;

// o(n3) o(1)
int brute(int arr[], int n, int k){
    int cnt{};
    for (int i{} ; i<n ; ++i){
        for (int j{i} ; j<n ; ++j){
            int sum{};
            for (int l{i} ; l<=j ; ++l){
                sum += arr[l];
            }
            if (sum == k) cnt++;
        }
    }
    return cnt;
}

// o(n2) o(1)
int better(int arr[], int n, int k){
    int cnt{};
    for (int i{} ; i<n ; ++i){
        int sum{};
        for (int j{i} ; j<n ; ++j){
            sum += arr[j];
            if (sum==k){
                cnt++;
            }
        }
    }
    return cnt;
}

// o(n) o(n) using presum map
int optimal(int arr[], int n, int k){
    unordered_map<int,int> presumMap;
    int presum{};
    int rem{};
    int cnt{};

    presumMap[0]=1;
    for (int i{} ; i<n ; ++i){
        presum += arr[i];
        // if (presum==k) cnt++;
        rem = presum - k;
        if (presumMap.find(rem) != presumMap.end()){
            cnt += presumMap[rem];
        }
        presumMap[presum]++;
    }
    return cnt;
}

int main() {
    int arr[]{3, 1, 2, 4};
    int k{6};
    int count{};
    // count = brute(arr, size(arr), k);
    // count = better(arr, size(arr), k);
    count = optimal(arr, size(arr), k);
    cout << "Number of subarrays whose sum equals " << k << " : " << count;
    return 0;
}
