#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void usemap(int a1[], int a2[], int n1, int n2){
    unordered_map<int,int> mpp;
    vector<int> temp;
    for (int i{0} ; i<n1 ; ++i) mpp[a1[i]];
    for (int i{0} ; i<n2 ; ++i) mpp[a2[i]];
    for (auto it=mpp.begin() ; it!=mpp.end() ; ++it) temp.emplace_back(it->first);
    sort(temp.begin(), temp.end());
    for (int i{0} ; i<size(temp) ; ++i) cout << temp[i] << " ";
}

void useset(int a1[], int a2[], int n1, int n2){
    unordered_set<int> S;
    vector<int> temp;
    for (int i{0} ; i<n1 ; ++i) S.insert(a1[i]);
    for (int i{0} ; i<n2 ; ++i) S.insert(a2[i]);
    for (auto it : S) temp.emplace_back(it);
    sort(temp.begin(), temp.end());
    for (int i{0} ; i<size(temp) ; ++i) cout << temp[i] << " ";
}

// this will merge the two arrays with duplicates.
// void use2ptr(int a1[], int a2[], int n1, int n2){
//     vector<int> Union;
//     int i{0},j{0};
//     while (i<n1 && j<n2){
//         if (a1[i]<a2[j]) {
//             Union.emplace_back(a1[i]);
//             ++i;
//         } else {
//             Union.emplace_back(a2[j]);
//             ++j;
//         }
//     }
//     while (i<n1){
//         Union.emplace_back(a1[i]);
//         ++i;
//     }
//     while (j<n2){
//         Union.emplace_back(a2[j]);
//         ++j;
//     }
//     for (int it : Union) cout << it << ' ';
// }

void use2ptr(int a1[], int a2[], int n1, int n2){
    vector<int> Union;
    int i{0},j{0};
    while (i<n1 && j<n2) {
        if (a1[i]<a2[j]){
            if (i==0 || (a1[i] != a1[i-1])) Union.emplace_back(a1[i]);
            ++i;
        }
        else if (a2[j]<a1[i]) {
            if (j==0 || (a2[j] != a2[j-1])) Union.emplace_back(a2[j]);
            ++j;
        }
        else {
            Union.emplace_back(a1[i]);
            ++i; ++j;
        }
    }
    while (i<n1){
        if (a1[i] != a1[i-1]) Union.emplace_back(a1[i]);
        ++i;
    }
    while (j<n2){
        if (a2[j] != a2[j-1]) Union.emplace_back(a2[j]);
        ++j;
    }
    for (int it : Union) cout << it << ' ';
}

int main() {
    int arr1[]{1,2,2,4,6};
    int arr2[]{2,3,4,5,5,5};
    // usemap(arr1, arr2, size(arr1), size(arr2));
    // useset(arr1, arr2, size(arr1), size(arr2));
    use2ptr(arr1, arr2, size(arr1), size(arr2));
    return 0;
}
