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
void pattern10(int n){ // n is the number of rows in the upper half of the pattern
    for (int i{0};i<2*n-1;i++){
        if (i<n){
            for (int j{0};j<(i+1);j++){
                cout<<'*';
            }
        }
        else {
            for (int k{2*n-1-i};k>0;k--){
                cout<<'*';
            }
        }
        cout<<'\n';
    }
}// Solved in the most complicated way but I am a fool so no problem :)

// 1
// 01
// 101
// 0101
// 10101
void pattern11(int n){
//     for (int i{0};i<n;i++){
//         if (i%2==0){
//             for (int j{0};j<i+1;j++){
//                 if (j%2==0){
//                     cout<<'1';
//                 }
//                 else{
//                     cout<<'0';
//                 }
//             }
//         }
//         else {
//             for (int k{0};k<i+1;k++){
//                 if (k%2==0){
//                     cout<<'0';
//                 }
//                 else{
//                     cout<<'1';
//                 }
//             }
//         }
//         cout<<'\n';
//     }
    int start{1};
    for (int i{0};i<n;i++){
        if (i%2==0) start = 1;
        else start = 0;
        for (int j{0};j<i+1;j++){
            cout<<start;
            start=1-start;
        }
        cout<<'\n';
    }
}

// 1      1
// 12    21
// 123  321
// 12344321
/*
PYTHON CODE
for i in range (0,n,1):
    for j in range (0,i+1,1):
        print(j+1,end='')
    for k in range(2*(n-i)-2,0,-1):
        print(' ',end='')
    for l in range (i+1,0,-1):
        print(l,end='')
    print()
*/
void pattern12(int n){
    for (int i{0};i<n;i++){
        for (int j{0};j<i+1;j++){
            cout<<j+1;
        }
        for (int k{2*(n-i)-2};k>0;k--){
            cout<<' ';
        }
        for (int l{i+1};l>0;l--){
            cout<<l;
        }
        cout<<'\n';
    }
}

void pattern13(int n){
    
}

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
    pattern10(5);
    pattern11(5);
    pattern12(4);
    return 0;
}
