#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeSpaces(string s) {
    string noSpc = "";
    for (char c : s) {
        if (c != ' ') {
            noSpc += c;
        }
    }
    return noSpc;
}

void solve(int caseNum) {
    string teamOut;
    string judgeOut;
    getline(cin, teamOut);
    getline(cin, judgeOut);

    cout << "Case " << caseNum << ": ";

    if (teamOut == judgeOut) {
        cout << "Yes\n";
    }
    else if (removeSpaces(teamOut) == judgeOut) {
        cout << "Output Format Error\n";
    }
    else {
        cout << "Wrong Answer\n";
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}