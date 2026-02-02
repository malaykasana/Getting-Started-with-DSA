#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort on the array
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void selection_sort(vector<int> &arr, size_t n){
    for (size_t i{};i<=n-2;++i){
        size_t mini{i};
        for (size_t j{i};j<=n-1;++j){
            if (arr[j]<arr[mini]) mini = j;
        }
        swap(arr[i],arr[mini]);
    }
}

// Function to perform bubble sort on the array
// Time Complexity: O(n^2) and for best case is O(N) when it breaks on 1 loop.
// Space Complexity: O(1)
void bubble_sort(vector<int> &arr, size_t n){
    for (size_t i{n-1};i>0;--i){
        int didswap{0};
        for (size_t j{0};j<=i-1;++j){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap=1;
            }
        }
        if (didswap==0){
            break;
        }
    }
}

// Function to perform insertion sort on the array
// Time Complexity: O(n^2) and for best case is O(N) when array is already sorted.
// Space Complexity: O(1)
void insertion_sort(vector<int> &arr,size_t n){
    for (size_t i{};i<n;++i){
        size_t j=i;
        while (j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

// Selection sort using Reverse technique
// Instead of starting from the front (index 0) and building sorted portion on left,
// this starts from the back (index n-1) and builds sorted portion on right.
// In each iteration:
// - Loop runs from i = n-1 down to 1 (processing from right to left)
// - Find the MAXIMUM element in the unsorted portion (from 0 to i)
// - Place it at position i (rightmost position of unsorted portion)
// This fills the array from right to left with largest elements
void reverse_selection_sort(vector<int> &arr, size_t n){
    for (size_t i{n-1};i>=1;--i){        // Start from end, move left
        size_t maxi{i};                   // Assume current position has max
        for (size_t j{i};j<=n-1;++j){    // Scan from i to end
            if (arr[j]>arr[maxi]) maxi = j;  // Find maximum element
        }
        swap(arr[i],arr[maxi]);           // Place max at position i
    }
}

// Bubble sort using Reverse technique
// Traditional bubble sort counts down (i from n-1 to 0) and pushes largest elements to the right.
// This reverse version counts up (i from 0 to n-1) and pushes smallest elements to the left.
// In each iteration:
// - Outer loop i tracks how many elements are already sorted at the END
// - Inner loop bubbles elements from start, but stops earlier each time (n-2-i)
// - After each pass, one more large element settles at the right side
// Result: sorted array is built from right to left (largest elements settle first)
void reverse_bubble_sort(vector<int> &arr, size_t n){
    for (size_t i{};i<n-1;++i){          // i tracks number of sorted elements at end
        int didswap{0};                   // Optimization flag
        for (size_t j{0};j<=n-2-i;++j){  // Reduce range each pass (n-2-i shrinks)
            if (arr[j]>arr[j+1]){         // Bubble larger element right
                swap(arr[j],arr[j+1]);
                didswap=1;
            }
        }
        if (didswap==0){                  // If no swaps, array is sorted
            break;
        }
    }
}

// Insertion sort using Reverse technique
// Traditional insertion sort starts from left (index 1) and inserts each element into
// the sorted left portion by shifting left.
// This reverse version starts from right (index n-1) and inserts each element into
// the sorted right portion by shifting RIGHT.
// In each iteration:
// - Start from the end (i = n-1) and move towards the front
// - Take element at position i and move it RIGHT to its correct position
// - While current element is greater than next element, swap and move right
// Result: sorted portion grows from right to left
void reverse_insertion_sort(vector<int> &arr,size_t n){
    for (size_t i{n-1};i>0;--i){         // Start from end, move towards front
        size_t j=i;                       // j is position of element to insert
        while (j<n-1 && arr[j]>arr[j+1]){ // While element is out of order (too large)
            swap(arr[j],arr[j+1]);        // Move element to the right
            j++;                           // Continue moving right
        }
    }
}

int main() {
    size_t n;
    cin >> n;
    vector<int> arr(n);
    for (size_t i{0};i<n;++i) cin>> arr[i];
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    insertion_sort(arr,n);
    for (size_t i{0};i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}
