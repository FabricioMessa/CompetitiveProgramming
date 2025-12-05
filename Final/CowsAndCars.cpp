#include <iostream>
#include <iomanip>

using namespace std;

void solve() {
    double n_cows, n_cars, n_show;
    while (cin >> n_cows >> n_cars >> n_show) {
        double total_doors = n_cows + n_cars;
        double doors_to_switch = total_doors - 1 - n_show;
        double p_start_cow = (n_cows / total_doors) * (n_cars / doors_to_switch);
        double p_start_car = (n_cars / total_doors) * ((n_cars - 1) / doors_to_switch);
        double total_probability = p_start_cow + p_start_car;
        cout << fixed << setprecision(5) << total_probability << "\n";
    }
}

int main() {
    solve();
    return 0;
}