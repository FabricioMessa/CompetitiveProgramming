#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int read_int(int k) {
    int val = 0;
    char c;
    int count = 0;
    while (count < k) {
        if (!(cin >> c)) return -1;
        val = (val << 1) | (c - '0'); 
        count++;
    }
    return val;
}

void sol() {
    string header;
    while (getline(cin, header)) {
        if (header.empty()) {
            continue;
        }
        while (true) {
            int len = read_int(3);
            if (len == 0) break;
            int base_index = 0;
            for (int i = 1; i < len; ++i) {
                base_index += (1 << i) - 1; 
            }

            while (true) {
                int val = read_int(len);
                if (val == (1 << len) - 1) {
                    break; 
                }
                cout << header[base_index + val];
            }
        }
        cout << "\n"; 
        char c;
        while(cin.get(c) && c != '\n'); 
    }
}

int main() {
    sol();
    return 0;
}