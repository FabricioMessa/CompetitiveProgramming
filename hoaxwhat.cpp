#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int dias;
	while (cin >> dias && dias != 0) {
		long long total = 0;
		multiset<int> urna;
		for (int i = 0; i < dias; ++i) {
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j) {
				int bill;
				cin >> bill;
				urna.insert(bill);
			}

			if (urna.size() >= 2) {
                int menor = *urna.begin();
				int mayor = *urna.rbegin();

				total += (mayor - menor);

				urna.erase(urna.begin());
				urna.erase(prev(urna.end()));
			}
		}
		cout << total << endl;
	}
    return 0;
}
