#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main () {
	int T;
	string A, B;

	cin >> T;

	for (int i=0 ; i<T ; i++) {
		cin >> A;
		cin >> B;

		int nb0=0;
		int nb1=0;
		int diff0=0;
		int diff1=0;

		string::iterator it = B.begin();
		for (char & c : A) {
			if (c == '0')
				nb0++;
			else
				nb1++;

			char c2 = *it;
			if (c != c2)
				if (c == '0')
					diff0++;
				else
					diff1++;

			++it;
		}

		if (nb0 == 0 || nb1 == 0) {
			cout << "Unlucky Chef" << endl;
			continue;
		}

		cout << "Lucky Chef" << endl;

		int val = max(diff0, diff1);

		cout << val << endl;
	}

	return 0;
}