#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// // Generate all permutations in sorted order
// // Linear or binary search to find the given permutation
// // return permutation at next index and if at last index return 1st permutation
// void permute(int ds[],int currentsizeofds, int arr[],int n, int* ans[],int& index, int hash[]){
//     if (currentsizeofds==n){
//         // add ds to ans
//         for(int i = 0; i < n; i++)
//             ans[index][i] = ds[i];
//         index++;
//         return;
//     }
//     for (int i{} ; i<n ; ++i){
//         if (hash[i]==0){
//             // add arr[i] to ds
//             hash[i]=1;
//             ds[currentsizeofds] = arr[i];
//             permute( ds,currentsizeofds+1 , arr,n , ans,index , hash );
//             hash[i]=0;
//             // remove last element from ds
//         }
//     }
// }

// /*
// // Notice ans is just int*
// void permute(int ds[], int currentsizeofds, int arr[], int n, int ans[], int& index, int hash[]){
//     if (currentsizeofds == n) {
//         // Deep copy into the 1D array using our magic formula
//         for(int i = 0; i < n; i++) {
//             // Formula: (Row * NumberOfColumns) + CurrentColumn
//             ans[(index * n) + i] = ds[i];
//         }
//         index++; // We finished a "row", so increment the conceptual row counter
//         return;
//     }
//     for (int i{} ; i<n ; ++i){
//         if (hash[i]==0){
//             // add arr[i] to ds
//             hash[i]=1;
//             ds[currentsizeofds] = arr[i];
//             permute( ds,currentsizeofds+1 , arr,n , ans,index , hash );
//             hash[i]=0;
//             // remove last element from ds
//         }
//     }
// }
// */

// // generate all permutations in ans array
// int** allP(int arr[], int n){
//     int total{1};
//     for (int i{1} ; i<=n ; ++i) total *= i;

//     int** ans = new int*[total]{};           // total permutations
//     for(int i = 0; i < total; i++) 
//         ans[i] = new int[n]{};               // each permutation has n elements
//     int index{};

//     int* ds = new int [n]{};
//     int currentsizeofds{};

//     int* hash = new int[n]{};  // Only need n slots for n elements

//     permute(ds,currentsizeofds, arr,n, ans,index, hash);
//     delete [] ds;
//     delete [] hash;
//     return ans;
// }

// /*
// int* allP(int arr[], int n) {
//     int total{1};
//     for (int i{1} ; i <= n ; ++i) total *= i;

//     // BAM! One single, massive contiguous block of memory. (Size = total * n)
//     int* ans = new int[total * n]{}; 

//     int index{};
//     int* ds = new int[n]{};
//     int sizeofds{};
//     int* hash = new int[n]{}; 

//     // Notice ans is now just int*, not int**
//     permute(ds, sizeofds, arr, n, ans, index, hash);

//     delete[] ds;
//     delete[] hash;
//     return ans; // Return the giant 1D array
// }
// */

// void brute (int arr[], int n){
//     // Generate ALL permutations
//     // ------All permutations will be in sorted order if we first sort the input array-------
//     int** allPermutations = allP(arr, n);
    
//     // Calculate total permutations (n!)
//     int total = 1;
//     for(int i = 1; i <= n; i++) total *= i;
    
//     // Print all sorted permutations
//     cout << "All permutations (sorted):" << endl;
//     for(int p = 0; p < total; p++){
//         for(int i = 0; i < n; i++){
//             cout << allPermutations[p][i] << " ";
//         }
//         cout << endl;
//     }
    
//     // Find current permutation in the sorted list
//     int currentIndex = -1;
//     for(int p = 0; p < total; p++){
//         bool isMatch = true;
//         for(int i = 0; i < n; i++){
//             if(allPermutations[p][i] != arr[i]){
//                 isMatch = false;
//                 break;
//             }
//         }
//         if(isMatch){
//             currentIndex = p;
//             break;
//         }
//     }
    
//     // Print next permutation
//     cout << "\nCurrent permutation: ";
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     cout << "Next permutation: ";
//     if(currentIndex != -1 && currentIndex < total - 1){
//         for(int i = 0; i < n; i++){
//             cout << allPermutations[currentIndex + 1][i] << " ";
//         }
//     } else {
//         // If at last permutation, wrap to first
//         for(int i = 0; i < n; i++){
//             cout << allPermutations[0][i] << " ";
//         }
//     }
//     cout << endl;
    
//     // Free memory
//     for(int i = 0; i < total; i++) delete[] allPermutations[i];
//     delete[] allPermutations;
// }

// improve space complexity by directly producing all permutations using pointers and swapping
void f(int arr[],int n , int total,int ans[],int index, int& row_cnt){
    if (index==n){
        for (int i{} ; i<n ; ++i){
            ans[index*row_cnt+i]=arr[i];
        }
        ++row_cnt;
        return;
    }
    for (int i{index} ; i<n ; ++i){
        swap(arr[index],arr[i]);
        f(arr, n, total, ans, index+1,row_cnt);
        swap(arr[index],arr[i]);
    }
}

int* brute(int arr[], int n){
    int total{1};
    for (int i{1} ; i<=n ; ++i) total *= i;
    
    int* ans = new int [total*n]{};

    // initially
    int row_cnt{};
    
    f(arr,n,total,ans,0,row_cnt);
    return ans;
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
    int givenarr[]{2,1,3};
    int arr[size(givenarr)]{};
    for(int i = 0; i < size(givenarr); i++) arr[i] = givenarr[i];
    sort(arr, arr + size(arr)); // Sort the array to ensure permutations are generated in sorted order
    
    int* ans{brute(arr, size(arr))};
    for (int i{} ; i<3 ; ++i) swap(ans[12+i],ans[15+i]); // correct the order generated at the last 2 rows
    for (int i{} ; i<18 ; ++i){
        if (i%3==0) cout<<'\n';
        cout << ans[i] << ' ';
    }
    delete [] ans;

    // int** ans{allP(arr, size(arr))};
    // for (int i{} ; i<6 ; ++i) cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    // delete[] ans;

    // better (givenarr, size(arr));
    // for (int it : arr) cout << it << ' ';
    // cout << endl;
    // optimal (givenarr, size(arr));
    return 0;
}
