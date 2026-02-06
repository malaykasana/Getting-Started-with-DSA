#include <iostream>
using namespace std;

void printarray(int arr[],int size){
    cout << '[';
    for (int i{0} ; i<size ; ++i) cout << arr[i] << ' ' ;
    cout << ']';
}

// find largest element in an array
// Brute force method was to sort the array and then printing the 1st element
void largest(int arr[],int size){
    int greatest{arr[0]};
    for (int i{1} ; i<size ; ++i){
        if (arr[i]>greatest) greatest=arr[i];
        // or greatest = min(arr[i],greatest); this has better clarity.
    }
    cout<< "The greatest number in the array ";
    printarray(arr,size);
    cout << " is "<<greatest;
}

// Find smallest, second smallest, largest and second largest element in array
// Brute force [O(N log N) , O(1)]
// is to sort the array and find the elements
// Better [O(N), O(1)] Two linear traversals
// /*
void better(int arr[], int size){
    if (size == 1) {
        cout<<-1;
        return;
    }
    int greatest{arr[0]},smallest{arr[0]};
    for (int i{1} ; i<size ; ++i){
        if (arr[i]>greatest) greatest=arr[i];
        if (arr[i]<smallest) smallest=arr[i];
    }
    int great2nd{arr[0]},small2nd{arr[0]};
    for (int i{1} ; i<size ; ++i){
        if (arr[i]>great2nd && arr[i]<greatest) great2nd=arr[i];
        if (arr[i]<small2nd && arr[i]>smallest) small2nd=arr[i];
    }
    cout << "The greatest, second greatest, smallest and second smallest numbers in the array ";
    printarray(arr,size);
    cout << " are " << greatest << ' ' << great2nd << ' ' << smallest << ' ' << small2nd;
}
// Optimal Solution []

int main() {
    int arr[2]{12,32};
    int size{sizeof(arr)/ sizeof(arr[0])};
    // largest(arr, size(arr));
    better(arr,size); // can also directly use size(array)
    return 0;
}
