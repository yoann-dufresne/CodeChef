#include <iostream>
#include <algorithm>

using namespace std;


int main () {
	int nbChews, hardness;

	cin >> nbChews >> hardness;
	int chews [nbChews] = {};
	for (int i=0 ; i<nbChews ; i++)
		cin >> chews[i];

	sort(chews, chews+nbChews);

	long long begin=0, end=nbChews-1;
	long long sum = 0;
	while (begin < end) {
		if (chews[end] + chews[begin]>= hardness)
			end--;
		else if (chews[end] + chews[begin+1] < hardness)
			begin++;
		else {
			sum += begin+1;
			end--;
		}
	}
	sum += end*(end+1)/2;

	cout << sum << endl;
}
