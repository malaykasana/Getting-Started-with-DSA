#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>

// Merge Sort.
// TC -> O(n log n)
// SC -> O(n)
/*
void merge(std::vector<int> &arr, int low, int mid, int high){
    std::vector<int> temp;
    int left{low};
    int right{mid+1};
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.emplace_back(arr[left]);
            ++left;
        }
        else{
            temp.emplace_back(arr[right]);
            ++right;
        }
    }
    while (left<=mid){
        temp.emplace_back(arr[left]);
        ++left;
    }
    while (right<=high){
        temp.emplace_back(arr[right]);
        ++right;
    }
    for (int i{0} ; i<temp.size() ; ++i){
        arr[low+i]=temp[i];
    }
    return;
}*/
void merge(std::vector<int> &arr, size_t low, size_t mid, size_t high){
    std::vector<int> temp;
    size_t left{low};
    size_t right{mid+1};
    while(left<=mid && right<=high){
        if (arr[left]<=arr[right]){
            temp.emplace_back(arr[left]);
            ++left;
        }
        else {
            temp.emplace_back(arr[right]);
            ++right;
        }
    }
    while(left<=mid){
        temp.emplace_back(arr[left]);
        ++left;
    }
    while(right<=high){
        temp.emplace_back(arr[right]);
        ++right;
    }
    for (size_t i{0};i<temp.size();++i){
        arr[low+i]=temp[i];
    }
}

void Divide(std::vector<int> &arr,size_t low, size_t high){
    if (low >= high) return;
    size_t mid{(low+high)/2};
    Divide(arr, low, mid);
    Divide(arr, mid+1, high);
    merge(arr,low,mid,high);
    return;
}

void divide(std::vector<int> &arr , int low , int high){
    if (low>=high) return;
    int mid{(low+high)/2};
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
    return;
}

// Quick Sort.
// TC -> O(n log n) on average , O(n^2) in worst case
// SC -> O(log n)

int main(){
    std::cout<<"This is starting.";
    std::vector<int> arr{1,10,20,50,100,200};
    int low{0};
    int high{arr.size()-1};
    divide(arr,low,high);
    for (int i{low} ; i<=high ; ++i){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<"This is end.";
    return 0;
}
