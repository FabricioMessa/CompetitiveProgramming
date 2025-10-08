#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int casos;
    vector<int> upLevel;
    vector<int> torre;
    int n;
    int cajas;
    while(cin >> cajas){
        while(cajas--){
            cin >> n;
            if(torre.empty()){
                upLevel.push_back(n);
                torre.push_back(n);
            }
            else{
                sort(torre.begin(),torre.end());
                auto it = lower_bound(torre.begin(),torre.end(),n);
                if(it == torre.end()){
                    upLevel.push_back(n);
                    torre.push_back(n);
                }
                else{
                    *it = *it - n;
                    torre.push_back(n);
                }
            }
        }
        int sum = accumulate(upLevel.begin(), upLevel.end(),0);
        cout << sum << '\n';
        upLevel.clear();
        torre.clear();
    }
    return 0;
}