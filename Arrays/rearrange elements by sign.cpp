#include <iostream>
#include <vector>
using namespace std;

// o(2n) , o(n)
void brute(int arr[], int n){
    vector<int> pos;
    vector<int> neg;
    for (int i{} ; i<n ; ++i){
        if (arr[i]>=0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }
    // since +ve and -ve elements are equal
    for (int i{} ; i<n/2 ; ++i){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    for (int i{} ; i<n ; ++i){
        cout << arr[i] << ' ';
    }
}

vector<int> optimal(int arr[], int n){
    int pos{}, neg{1};
    vector<int> temp(n,0);
    for (int i{} ; i<n ; ++i){
        if (arr[i]>=0) {
            temp[pos]=arr[i];
            pos += 2;
        }
        else {
            temp[neg]=arr[i];
            neg += 2;
        }
    }
    return temp;
}

// if (no. of +ve != no. of -ve ) _____ then we fall back to brute method
void brute1(int arr[], int n){
    vector<int> pos, neg;
    for (int i{} ; i<n ; ++i){
        if (arr[i]>=0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }
    if (pos.size()>=neg.size()){
        for (int i{} ; i<neg.size() ; ++i){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index{2*neg.size()};
        for (int i{neg.size()} ; i<pos.size() ; ++i){
            arr[index++]=pos[i];
        }
    }
    else {
        for (int i{} ; i<pos.size() ; ++i){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int nindex{pos.size()};
        for (int i{2*pos.size()} ; i<n ; ++i){
            arr[i]=neg[nindex++];
        }
    }
    for (int i{} ; i<n ; ++i){
        cout << arr[i] << ' ';
    }
}

int main() {
    int arr[]{1,2,-4,-3,-1,-2,3};
    // brute(arr, size(arr));
    {
        // vector<int> ar = optimal(arr, size(arr));
        // for (int i{} ; i<size(arr) ; ++i) cout << ar[i] <<' ';
    }
    brute1(arr, size(arr));
    return 0;
}
