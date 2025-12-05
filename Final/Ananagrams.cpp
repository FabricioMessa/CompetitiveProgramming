#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <map>     

using namespace std;

string canon(string s) {
    string sl = s;
    for (int i = 0; i < sl.length(); ++i) {
        sl[i] = tolower(sl[i]);
    }
    sort(sl.begin(), sl.end());
    return sl;
}

void solucion() {
    vector<string> dicc;
    string word;
    map<string, int> counts;

    while (cin >> word) {
        if (word == "#") {
            break;
        } 
        dicc.push_back(word);
        string canonical = canon(word);
        counts[canonical]++;
    }

    vector<string> ananagrams;
    for (const string& w : dicc) {
        if (counts[canon(w)] == 1) {
            ananagrams.push_back(w);
        }
    }

    sort(ananagrams.begin(), ananagrams.end());
    for (const string& w : ananagrams) {
        cout << w << "\n";
    }
}

int main() {
    solucion();  
    return 0;
}