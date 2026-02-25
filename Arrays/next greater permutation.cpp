#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Generate all permutations in sorted order
// Linear or binary search to find the given permutation
// return permutation at next index and if at last index return 1st permutation
void permute(int ds[],int sizeofds, int arr[],int n, int* ans[],int& index, int hash[]){
    if (sizeofds==n){
        // add ds to ans
        for(int i = 0; i < n; i++)
            ans[index][i] = ds[i];
        index++;
        return;
    }
    for (int i{} ; i<n ; ++i){
        if (hash[i]==0){
            // add arr[i] to ds
            hash[i]=1;
            ds[sizeofds] = arr[i];
            permute( ds,sizeofds+1 , arr,n , ans,index , hash );
            hash[i]=0;
            // remove last element from ds
        }
    }
}
/*
// Notice ans is just int*
void permute(int ds[], int sizeofds, int arr[], int n, int* ans, int& index, int hash[]){
    if (sizeofds == n) {
        // Deep copy into the 1D array using our magic formula
        for(int i = 0; i < n; i++) {
            // Formula: (Row * NumberOfColumns) + CurrentColumn
            ans[(index * n) + i] = ds[i];
        }
        index++; // We finished a "row", so increment the conceptual row counter
        return;
    }
    // ... the rest of the backtracking for loop remains exactly the same!
// }
*/
// generate all permutations in ans array
int** allP(int arr[], int n){
    int total{1};
    for (int i{1} ; i<=n ; ++i) total *= i;

    int** ans = new int*[total];           // total permutations
    for(int i = 0; i < total; i++) 
        ans[i] = new int[n];               // each permutation has n elements
    int index{};

    int* ds = new int [n]{};
    int sizeofds{};

    int* hash = new int[n]{};  // Only need n slots for n elements

    permute(ds,sizeofds, arr,n, ans,index, hash);
    delete [] ds;
    delete [] hash;
    return ans;
}
/*
int* allP(int arr[], int n) {
    int total{1};
    for (int i{1} ; i <= n ; ++i) total *= i;

    // BAM! One single, massive contiguous block of memory. (Size = total * n)
    int* ans = new int[total * n]{}; 

    int index{};
    int* ds = new int[n]{};
    int sizeofds{};
    int* hash = new int[n]{}; 

    // Notice ans is now just int*, not int**
    permute(ds, sizeofds, arr, n, ans, index, hash);

    delete[] ds;
    delete[] hash;
    return ans; // Return the giant 1D array
}
*/
void brute (int arr[], int n){
    // Generate ALL permutations
    int** allPermutations = allP(arr, n);
    
    // Calculate total permutations (n!)
    int total = 1;
    for(int i = 1; i <= n; i++) total *= i;
    
    // Sort all permutations in lexicographic order
    for(int p1 = 0; p1 < total - 1; p1++){
        for(int p2 = p1 + 1; p2 < total; p2++){
            // Compare two permutations
            bool swap_needed = false;
            for(int i = 0; i < n; i++){
                if(allPermutations[p1][i] > allPermutations[p2][i]){
                    swap_needed = true;
                    break;
                } else if(allPermutations[p1][i] < allPermutations[p2][i]){
                    break;
                }
            }
            // Swap if needed
            if(swap_needed){
                int* temp = allPermutations[p1];
                allPermutations[p1] = allPermutations[p2];
                allPermutations[p2] = temp;
            }
        }
    }
    
    // Print all sorted permutations
    cout << "All permutations (sorted):" << endl;
    for(int p = 0; p < total; p++){
        for(int i = 0; i < n; i++){
            cout << allPermutations[p][i] << " ";
        }
        cout << endl;
    }
    
    // Find current permutation in the sorted list
    int currentIndex = -1;
    for(int p = 0; p < total; p++){
        bool isMatch = true;
        for(int i = 0; i < n; i++){
            if(allPermutations[p][i] != arr[i]){
                isMatch = false;
                break;
            }
        }
        if(isMatch){
            currentIndex = p;
            break;
        }
    }
    
    // Print next permutation
    cout << "\nCurrent permutation: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Next permutation: ";
    if(currentIndex != -1 && currentIndex < total - 1){
        for(int i = 0; i < n; i++){
            cout << allPermutations[currentIndex + 1][i] << " ";
        }
    } else {
        // If at last permutation, wrap to first
        for(int i = 0; i < n; i++){
            cout << allPermutations[0][i] << " ";
        }
    }
    cout << endl;
    
    // Free memory
    for(int i = 0; i < total; i++) delete[] allPermutations[i];
    delete[] allPermutations;
}

// use C++ STL
void better (int arr[], int n){
    next_permutation(arr, arr+n);
}

// write C++ STL next_permutation() code manually
void optimal(int arr[], int n){
    int index{-1};
    for (int i{n-2} ; i>=0 ; --i){
        if (arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if (index==-1){
        reverse(arr,arr+n);
    }
    for (int i{n-1} ; i>index ; --i){
        if (arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr+index+1,arr+n);
    for (int i{} ; i<n ; ++i){
        cout << arr[i] << ' ';
    }
}

int main() {
    int arr[]{1,2,3};
    // brute(arr, size(arr));
    int** ans{allP(arr, size(arr))};
    for (int i{} ; i<6 ; ++i) cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    delete[] ans;
    // better (arr, size(arr));
    // for (int it : arr) cout << it << ' ';
    // cout << endl;
    // optimal (arr, size(arr));
    return 0;
}
