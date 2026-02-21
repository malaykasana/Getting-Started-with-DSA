#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int left{low};
    int right{mid+1};
    int i{};
    int temp[high-low+1]{};
    while (left<=mid && right<=high){
        if (arr[left]<=arr[right]){
            temp[i]=arr[left];
            ++i;
            left++;
        }
        else {
            temp[i]=arr[right];
            ++i;
            ++right;
        }
    }
    while (left<=mid){
        temp[i]=arr[left];
        ++i;
        ++left;
    }
    while (right<=high){
        temp[i]=arr[right];
        ++i;
        ++right;
    }
    for (int i{} ; i<high-low+1 ; ++i){
        arr[low+i]=temp[i];
    }
}
void divide(int arr[], int low, int high){
    if (low>=high) return;
    int mid{(low+high)/2};
    divide(arr, low, mid);
    divide(arr, mid+1, high);
    merge(arr, low, mid, high);
}
void brute (int arr[], int n){
    divide(arr, 0, n-1);
    for (int i{} ; i<n ; ++i) cout << arr[i] << ' ';
}

void better(int arr[], int n){
    int num0{}, num1{}, num2{};
    for (int i{} ; i<n ; ++i){
        if (arr[i]==0) num0++;
        else if (arr[i]==1) num1++;
        else num2++;
    }
    for (int i{} ; i<num0 ; ++i) arr[i]=0;
    for (int i{num0} ; i<num0+num1 ; ++i) arr[i]=1;
    for (int i{num0+num1} ; i<n ; ++i) arr[i]=2;
    for (int i{} ; i<n ; ++i) cout<< arr[i] <<' ';
}

// dutch national flag algorithm - uses three pointers.
// 0s- low to low-1
// 1s- low to mid-1
// unsorted- mid to high
// 2s- high+1 to n-1
void optimal(int arr[], int n){
    int low{}, mid{}, high{n-1};
    while (mid<=high){
        if (arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1) mid++;
        else {
            swap (arr[mid], arr[high]);
            high--;
        }
    }
    for (int i{} ; i<n ; ++i) cout << arr[i] << ' ';
}

int main() {
    int arr[]{1,2,0,0,0,1,1,2,1};
    // brute(arr, size(arr));
    // better(arr, size(arr));
    optimal(arr, size(arr));
    return 0;
}
