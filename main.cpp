#include <iostream>
#include <map>

using namespace std;

int main () {
	int nbStacks, maxHeight;

	cin >> nbStacks >> maxHeight;
	int stacks[nbStacks] = {};

	for (int i=0 ; i<nbStacks ; i++)
		cin >> stacks[i];

	int position = 0;
	bool isLoad = false;

	int val;
	while ((cin >> val) != 0) {
		switch (val) {
			case 1:
				if (position != 0)
					position--;
			break;
			case 2:
				if (position != nbStacks-1)
					position++;
			break;
			case 3:
				if (!isLoad && stacks[position] > 0) {
					isLoad = true;
					stacks[position]--;
				}
			break;
			case 4:
				if (isLoad && stacks[position] < maxHeight) {
					isLoad = false;
					stacks[position]++;
				}
			break;
		}
	}

	for (int i=0 ; i<nbStacks ; i++)
		cout << stacks[i] << ' ';
	cout << endl;

	return 0;
}
