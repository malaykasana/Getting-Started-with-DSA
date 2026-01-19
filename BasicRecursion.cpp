#include <iostream>
using namespace std;

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