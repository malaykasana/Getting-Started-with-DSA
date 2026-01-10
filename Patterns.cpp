#include <iostream>
using namespace std;

// *****
// *****
// *****
// *****
// *****
void pattern1(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << '\n';
    }
}

// *
// **
// ***
// ****
// *****
void pattern2 (int n){
    for (int i{0}; i<n; i++){
        for (int j{0};j<i+1;j++){
            cout<<"* ";
        }
        cout<<'\n';
    }
}

// 1
// 12
// 123
// 1234
// 12345
void pattern3 (int n){
    for (int i{0}; i<n; i++){
        for (int j{0};j<i+1;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';
    }
}

// 1
// 22
// 333
// 4444
// 55555
void pattern4(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i+1;j++){
            cout<<i+1<<" ";
        }
        cout<<'\n';
    }
}

// 12345
// 1234
// 123
// 12
// 1
void pattern5(int n){
    for (int i{n};i>0;i--){
        for (int j{0};j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';

    }
}

//     *
//    **
//   ***
//  ****
// *****
void pattern6(int n){
    for (int i{n};i>0;i--){
        for (int j{0};j<i-1;j++){
            cout<<" ";
        }
        for (int k{0};k<n-i+1;k++){
            cout<<"*";
        }
        cout<<'\n';
    }
}

// *****
//  ****
//   ***
//    **
//     *
void pattern7(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i;j++){
            cout<<" ";
        }
        for (int k{n-i};k>0;k--){
            cout<<"*";
        }
        cout<<'\n';
    }
}

//    *
//   ***
//  *****
// *******
//*********
void pattern8(int n){
    for (int i{0}; i<n; i++){
        for (int j{n-i-1};j>0;j--){
            cout<<' ';
        }
        for (int l{2*i+1};l>0;l--){
            cout<<"*";
        }
        for (int k{n-1};k>0;k--){
            cout<<' ';
        }
    cout<<'\n';
    }
}

// Reverse of above case i.e. upside down triangle.
void pattern9(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i;j++){
            cout<<' ';
        }
        for (int k{0};k<2*(n-i)-1;k++){
            cout<<'*';
        }
        for (int l{0};l<i;l++){
            cout<<' ';
        }
    cout<<'\n';
    }
}

// Combined case for both triangles.
// void pattern10(int n){
//     for ()
// }

int main() {
    pattern1(5,5);
    pattern2(5);
    pattern3(5);
    pattern4(5);
    pattern5(5);
    pattern6(5);
    pattern7(5);
    pattern8(5);
    pattern9(5);
    return 0;
}
