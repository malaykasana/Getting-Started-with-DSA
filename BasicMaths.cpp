#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int countdigits(int n) {
    // int cnt = 0;
    // while (n>0){
    //     ++cnt;
    //     n=n/10;
    // }
    // return cnt;

    int cnt = static_cast<int>(log10(n)) + 1; // TC -> O( log10(N) )
    return cnt;
}

int reversenumber(int n){
    int revnum {0};
    while (n>0){
        int r{n%10};
        revnum = revnum*10+r;
        n /= 10;
    }
    return revnum;
}

bool ifpalindrome(int n){
    int dup{n};
    int revnum{reversenumber(n)};
    if (dup==revnum){
        return true;
    }
    else {
        return false;
    }
}

bool ifarmstrongfor3digit(int n){
    int dup{n};
    int sumofcubes{0};
    while (n>0){
        int r{n%10};
        n /= 10;
        sumofcubes += (r*r*r);
    }
    if (dup==sumofcubes){
        return true;
    }
    else {
        return false;
    }
}

void printdivisions(int n){ // TC -> O(N)
    // for (int i{1} ; i<=n ; ++i){
    //     if (n%i==0){
    //         cout<< i<<' ';
    //     }
    // }

    vector<int> ls;
    for (int i{1} ; i*i<=n ; ++i){ // TC -> O(sqrt(n))
        if (n%i==0){
            ls.emplace_back(i);
            if (n/i != i){
                ls.emplace_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end()); // O(no.of factors * log(no. of factors))
    for (auto it : ls) cout<< it << ' '; // O(no. of factors)
}

void ifprime(int n){
    if (n < 2) {
        cout << "It is not a prime number.";
        return;
    }

    int cnt{0};
    // for (int i{1} ; i<=n ; ++i){
    //     if (n%i==0){
    //         ++cnt;
    //     }
    // }

    for (int i{1} ; i*i<=n ; ++i){
        if (n%i==0){ 
            ++cnt;
            if ((n/i)!= i) ++cnt;
        }
    }
    if (cnt == 2) cout<<"It is a prime number.";
    else cout << "It is not a prime number.";
}

void printGcdHcf(int n1, int n2){
    // int gcd{};
    // for (int i{1} ; i<=min(n1,n2) ; ++i){ // O(min(n1,n2))
    //     if (n1%i==0 && n2%i==0) gcd=i;
    // }

    // Euclidean Algorithm
    // gcd(a,b)=gcd(a-b,b)  a>b
    // gcd(a,b)==gcd(a%b,b) a>b

    while (n1>0 && n2>0){ // O(log to base phi min(a,b))
        if (n1>n2) n1 %= n2;
        else n2 %= n1;
    }
    cout << "GCD = ";
    if (n1==0) cout<<n2;
    else cout<<n1;
}

int main(){
    int n{};
    cout<< "Enter a number : ";
    cin>> n;
    cout<<'\n';

    // int a = countdigits(n);
    // cout << "The number of digits in given number is "<<a;

    // int b = reversenumber(n);
    // cout<< "The reverse number is : "<< b <<'\n';

    // bool c{ifpalindrome(n)};
    // cout<< c;
    // // if (c==true){
    // //     cout << "The number is a palindrome.";
    // // }
    // // else {
    // //     cout << "The number is not a palindrome.";
    // // }

    // bool d{ifarmstrongfor3digit(n)};
    // cout<< d;

    // printdivisions(n);

    // ifprime(n);

    int n1{};
    int n2{};
    cout<< "Enter 2 numbers to check for prime : ";
    cin >> n1 >>n2;
    printGcdHcf(n1,n2);

    return 0;
}
