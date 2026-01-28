#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Number Hashing using frequency array
/*
int main() {
    unsigned int n;
    cin>>n;
    vector<int> vec(n);
    for (unsigned int i{};i<n;++i)   // O(N)
        cin>>vec[i]; 

    // precompute
    int hash[13]{};
    for (unsigned int i{};i<n;++i){  // O(Q)
        hash[vec[i]]++;
    }
    int q{};
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        // fetch
        cout << hash[number]<<'\n';
    }
    return 0;                         // O(Q*N)
}
*/

// Character Hashing using frequency array
/*
int main() {
    string s{};
    cin>>s;

    // Precompute
    int hash[26]{};
    for (unsigned int i{};i<s.size();++i){
        hash[s[i]-'a']++;    
    }

    // int hash[255]{};
    // for (unsigned int i{};i<s.size();++i){
    //     hash[s[i]]++;
    // }

    int q{};
    cin>>q;
    while (q--){
        char c{};
        cin >> c;
        //fetch
        cout<< hash[c-'a']<<'\n';
        // cout<< hash[c]<<'\n';
    }
    return 0;
}
*/

// Number Hashing using Map
// Can also use unordered_map for better average time complexity its just that map keeps the keys in sorted order
/*
#include <map>             // O(log N) operations
#include <unordered_map>   // O(1) average time complexity for best and average storing and fetching operations
                           // O(N) TC for worst case due to internal collisions i.e. when all keys hash to same bucket
int main() {
    unsigned int n{};
    cin>>n;
    vector<int> arr(n);
    // map<int,int> mpp;   // we can also declare map here and do precomputation in the input loop
    for(unsigned int i{};i<n;++i){
        cin>>arr[i];
        // precomputation here
        mpp[arr[i]]++;
    }

    // Precompute
    map<int,int> mpp;
    for (unsigned int i{};i<n;++i){
        mpp[arr[i]]++;
    }

    // Iterate through map
    // for (auto it:mpp){
    //     cout<<it.first<<"-->"<<it.second<<'\n';
    // }

    int q{};
    cin>>q;
    while (q--){
        int number{};
        cin>>number;
        // fetch
        cout<< mpp[number]<<'\n';
    }
}
*/

// Find the Highest and Lowest Frequency number in an array
#include <unordered_map>
int main() {
    unsigned int n{};
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> mpp;
    for (unsigned int i{};i<n;++i){
        cin>>arr[i];
        mpp[arr[i]]++;
    }
    int maxFreq{0}, minFreq{static_cast<int>(n)};
    int maxFreqNum{}, minFreqNum{};
    for (auto it:mpp){
        if (it.second > maxFreq){
            maxFreq = it.second;
            maxFreqNum = it.first;
        }
        if (it.second < minFreq){
            minFreq = it.second;
            minFreqNum = it.first;
        }
    }
    cout<<"Number with Highest Frequency: "<<maxFreqNum<<" Frequency: "<<maxFreq<<'\n';
    cout<<"Number with Lowest Frequency: "<<minFreqNum<<" Frequency: "<<minFreq<<'\n';
    return 0;
}
