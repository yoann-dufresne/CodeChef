#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	int N;

	cin >> N;
	int values [N] = {};
	for (int i=0 ; i<N ; i++)
		cin >> values[i];

	sort (values, values+N);

	long long val=0;
	long long result=0;
	for (int i=1 ; i<N ; i++) {
		val = values[i] - values[i-1];
		result += val * i * (N-i);
	}

	cout << result << endl;

	return 0;
}
