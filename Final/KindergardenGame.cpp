#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void sol() {
    string line;
    while (getline(cin, line)) {
        int count = 0;
        bool word = false;

        for (char c : line) {
            if (isalpha(c)) {
                if (!word) {
                    count++;
                    word = true;
                }
            } else {
                word = false;
            }
        }
        cout << count << "\n";
    }
}

int main() {
    sol();
    return 0;
}