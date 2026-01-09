#include <iostream>
using namespace std;

void pattern1(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2 (int m){
    for (int i{0}; i<m; i++){
        for (int j{0};j<i+1;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';
    }
}

void pattern3(int m){
    for (int i{0};i<m;i++){
        for (int j{0};j<i+1;j++){
            cout<<i+1<<" ";
        }
        cout<<'\n';
    }
}

void pattern4(int m){
    for (int i{m};i>0;i--){
        for (int j{0};j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';

    }
}
int main() {
    //pattern1(5,5);
    //pattern2(5);
    //pattern3(5);
    pattern4(5);
    return 0;
}
