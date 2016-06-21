#include <iostream>
#include <map>

using namespace std;

int main () {
	int N;

	cin >> N;

	map<long long,long long> scores;
	for (int i=0 ; i<N ; i++) {
		long long val;
		cin >> val;

		long nb = 1;
		map<long long,long long>::iterator it = scores.find (val);
		if (it != scores.end())  {
			nb += it->second;
		}

		scores[val] = nb;
	}

	long long sum = 0;
	long long max = 0;
	map<long long,long long>::iterator it = scores.end();
	do {
		it--;

		sum += it->second;
		long long val = it->first * sum;

		if (val > max)
			max = val;
	} while (it != scores.begin());

	cout << max << endl;

	return 0;
}
