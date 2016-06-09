#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


int main () {
	int N, Q;

	cin >> N >> Q;

	int min, max;
	cin >> min;
	max = min;

	for (int i=1 ; i<N ; i++) {
		int val;
		cin >> val;
		
		if (val < min)
			min = val;
		else if (val > max)
			max = val;
	}

	for (int i=0 ; i<Q ; i++) {
		int val;
		cin >> val;

		if (val >= min && val <= max)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}