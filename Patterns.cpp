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

void pattern2 (int m, int n){
    for (int i{0}; i<m; i++){
        for (int j{0};j<i+1;j++){
            cout<<j+1<<" ";
        }
        cout<<'\n';
    }
}

int main() {
    //pattern1(5,5);
    pattern2(5,5);

    return 0;
}
