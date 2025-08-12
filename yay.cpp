#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    if(s[0] == s[1]){
        for(int i = 2; i < s.length(); i++){
            if(s[i] != s[0]){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    else if(s[0] == s[2]){
        cout << 2 << endl;
    }
    else if(s[1] == s[2]){
        cout << 1 << endl;
    }

    return 0;
}