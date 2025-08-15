#include <iostream>
using namespace std;

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        int row=0;
        int warrior=0;
        cin >> n;
        if(n == 0){
            cout << 0 << endl;
        }
        if(n > 0){
            while(warrior <= n){
                row += 1;
                warrior = warrior + row;
            }
            cout << row << endl;
        }
    }    
    return 0;
}