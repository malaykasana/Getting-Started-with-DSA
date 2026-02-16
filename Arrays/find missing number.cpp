#include <iostream>
using namespace std;

// Given an array arr[] of size n-1 with distinct integers in the range of [1, n].
// This array represents a permutation of the integers from 1 to n with one element missing.
// Find the missing element in the array.

// O(n2), O(1)
int brute(int arr[], int n){
    for (int i{0} ; i<n+1 ; ++i){
        bool found{false};
        for (int j{0} ; j<n ; ++j){
            if (arr[j] == i+1){
                found=true;
                break;
            }
        }
        if (found==false) return i+1;
    }
    return -1;
}

// o(n), o(n)
int better(int arr[], int n){
    int hash[n+2]{};
    for (int i{0} ; i<n ; ++i){
        ++hash[arr[i]];
    }
    for (int i{1} ; i<=n+1 ; ++i){
        if (hash[i]==0) return i;
    }
    return -1;
}

// using sum formula and subtracting obtained sum
int sumformula(int arr[], int n){
    int sum{};
    int fsum{((n+1)*(n+2))/2};
    for (int i{} ; i<n ; ++i) sum += arr[i];
    return fsum-sum;
}

// using xor operator, xor of all elements and xor of 1 to n will give the missing number
// both numbers are distict -> 1
// a xor a = 0
// a xor 0 = a
int Xor(int arr[], int n){
    int num{};
    for (int i{1} ; i<=n+1 ; ++i){
        num=num^i;
    }
    int num2{};
    for (int i{} ; i<n ; ++i){
        num2 ^= arr[i];
    }
    return num^num2;
}

int main() {
    int arr[]{2,5,1,4,8,3,7};
    int n{sizeof(arr)/sizeof(arr[0])};
    // int miss{brute(arr, n)};
    // int miss{better(arr, n)};
    // int miss{sumformula(arr, n)};
    int miss{Xor(arr, n)};
    cout << miss;
    return 0;
}
