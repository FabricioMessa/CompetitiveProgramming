#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int CharInt(char c) {
    if (c == ' ') {
        return 0;
    }
    return c - 'A' + 1;
}

char IntChar(int v) {
    if (v == 0) { 
        return ' ';
    }
    return (char)(v - 1 + 'A');
}

string Decrypt(string s, int k) {
    string result = "";
    for (char c : s) {
        int val = CharInt(c);
        int decryptVal = (val - k + 27) % 27;
        result += IntChar(decryptVal);
    }
    return result;
}

void solve() {
    vector<string> dicc;
    string word;

    while (cin >> word && word != "#") {
        dicc.push_back(word);
    }

    string line;
    getline(cin, line); 
    string encryp;
    getline(cin, encryp);

    int bestK = 0;
    int maxMat = -1;
    string bestDecrypt = "";

    for (int k = 1; k <= 26; ++k) {
        string candidate = Decrypt(encryp, k);
        int matches = 0;
        stringstream ss(candidate);
        string token;
        while (ss >> token) {
            for (const string& d : dicc) {
                if (d == token) {
                    matches++;
                    break; 
                }
            }
        }

        if (matches > maxMat) {
            maxMat = matches;
            bestK = k;
            bestDecrypt = candidate;
        }
    }

    stringstream ssFinal(bestDecrypt);
    string token;
    string current = "";

    while (ssFinal >> token) {
        if (current.length() == 0) {
            current += token;
        } else {
            if (current.length() + 1 + token.length() <= 60) {
                current += " " + token;
            } else {
                cout << current << "\n";
                current = token;
            }
        }
    }
    if (current.length() > 0) {
        cout << current << "\n";
    }
}

int main() {
    solve();
    return 0;
}