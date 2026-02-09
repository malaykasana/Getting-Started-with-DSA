#include <iostream>
using namespace std;

// print numbers from 0 to 2 by recursion
/*
int cnt{0};
void print(){
    if (cnt == 3) return;
    cout<<cnt<<'\n';
    ++cnt;
    print();
}
int main() {
    print();
    return 0;
}
*/

// print name n times
/*
void f(int i,int n){        // TC -> O(N)
    if (i==n) return;       // SC -> O(N)
    cout<<"Malay"<<'\n';
    f(i+1,n);
}
int main(){
    int n{};
    int i{0};
    cin>>n;
    f(i,n);
    return 0;
}
*/

// print numbers 1 to n
/*
void f(int i,int n){
    if (i>n) return;
    else{
        cout<<i<<'\n';
        f(i+1,n);
    }
}
int main(){
    int n{};
    int i{1};
    cin>>n;
    f(i,n);
    return 0;
}
*/

// print numbers n to 1
/*
void f(int n){
    if (n<1) return;
    else{
        cout << n<<'\n';
        f(--n);
    }
}
int main(){
    // int i{1};
    int n{};
    cout<<"Print from   to 1.\033[7D";
    cin>>n;
    f(n);
    return 0;
}
*/

// print 1 to n by backtracking
/*
void f(int i){
    if (i<1) return;
    else{
        f(i-1);
        cout<<i<<'\n';
    }
}
int main(){
    int n{};
    cin>>n;
    f(n);
    return 0;
}
*/

// print n to 1 by backtracking
/*
void f(int i,int n){
    if (i>n) return;
    else{
        f(i+1,n);
        cout<<i<<'\n';
    }
}
int main(){
    int n{};
    int i{1};
    cin>>n;
    f(i,n);
    return 0;
}
*/

// Sum of first n numbers
// TC -> O(N)
/*
//PARAMETERISED WAY
void f(int n,int sum){
    if (n<1){
        cout<< sum;
        return;
    }
    else {
        f(int (n-1),int (sum+n));
        return;
    }
}
int main() {
    int n{};
    cout<< "Enter a number : ";
    cin >> n;
    cout<< "Sum of first "<< n<< " numbers is ";
    f(n,0);
    return 0;
}
*/
/*
// FUNCTIONAL WAY
int f(int n){
    if (n==0){
        return 0;
    }
    else {
        return (n+f(n-1));
    }
}
int main(){
    int n{};
    cout<< "Enter a number : ";
    cin >> n;
    int sum{f(n)};
    cout<< "Sum of first "<< n<< " numbers is "<< sum;
    return 0;
}
*/

// Factorial of N numbers
// TC -> O(N)
/*
void f(int n,int fac){
    if (n==1){
        cout<<fac;
        return;
    }
    else {
        f(n-1,fac*n);
    }
}
int main(){
    int n{};
    cout<< "Enter a number : ";
    cin >> n;
    cout<< "Factorial of "<< n<< " is ";
    f(n,1);
    return 0;
}
*/
/*
int f(int n){
    if (n==1){
        return 1; 
    }
    else {
        return n*f(n-1);
    }
}
int main(){
    int n{};
    cout<< "Enter a number : ";
    cin >> n;
    int fac{f(n)};
    cout<< "Factorial of "<< n<< " is "<< fac;
    return 0;
}
*/

// Arange the elements of an array in Reverse order  
/*
// TC -> O(N)
void f(int l, int r, int arr[]){
    if (l>=r) return;
    swap (arr[l],arr[r]);
    f(l+1,r-1,arr);
}
int main(){
    int arr[]={1,2,3,4,5};
    f(0,4,arr);
    for (int i{0};i<5;++i){
        cout<< arr[i];
    } 
}
*/
/*
// TC -> O(N/2)
#include <array>
void f(int i,int n,int arr[]){
    if (i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    f(i+1,n,arr);
}
int main(){
    int arr[]{1,2,3,4,5};
    f(0,size(arr),arr);
    for (int i{0};i<5;++i) cout<< arr[i];
}
*/

// Check if a string is palindrome
/*
// TC -> O(N/2)
#include <string>
bool ifpalindrome(int i,string &s){
    if (i>=s.size()/2) return true;
    if (s[i] != s[s.size()-i-1]) return false;
    return ifpalindrome(i+1,s);
}
int main(){
    string s{"madam"};
    cout<<ifpalindrome(0,s);
    return 0;
}
*/

// Multiple Function Calls
// Fibonacci Series
// 0 1 1 2 3 5 8 13 21 34 ... -> 0 is 0th term.
/*
f[0]=0 f[1]=1
for (i=2 -> n)
    f[i] = f[i-1] + f[i-2]
*/
// TC -> O(2^n) exponential in nature
/*
int f(int n){
    if (n<=1) return n;
    cout << "i have reached : "<< n << '\n';
    return f(n-1)+f(n-2);
}
int main(){
    int n{};
    cout<< "Enter a number (dont take it above 25 if you dont want to fry your pc) : ";
    cin>>n;
    cout << f(n);
    return 0;
}
*/
