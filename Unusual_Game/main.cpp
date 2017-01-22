#include <iostream>

using namespace std;

int eval (int turn, int col);
bool possible (int turn, int col);

char * dynamic;

int MAX;
int main () {
	int T;
	cin >> T;

	for (int i=0 ; i<T ; i++) {
		int m;
		cin >> MAX >> m;
		dynamic = (char *) malloc (MAX * 100 * sizeof(char));
		for (int i=0 ; i<MAX*MAX ; i++) {
			dynamic[i] = 0;
		}

		int col;
		for (int j=0 ; j<m ; j++) {
			cin >> col;
			int val = eval(1, col);
			cout << val << " ";
		}
		cout << endl;

		free (dynamic);
	}

	return 0;
}



#define IDX(turn, col) ((turn-1)*MAX + col-1)

int eval (int turn, int col) {
	//cout << "eval: " << turn << " " << col << endl;
	// --- Défaite ---
	if (!possible(turn, col)) {
		//cout << "Défaite base" << endl;
		return 2;
	}

	// --- Victoire ---
	if (col - turn > 0) {
		if (!possible(turn+1, col-turn)) {
			//cout << "victoire 1" << endl;
			return 1;
		}
	}
	if (col + turn <= MAX) {
		if (!possible(turn+1, col+turn)) {
			//cout << "victoire 2" << endl;
			return 1;
		}
	}

	// --- Récursions ---

	// Cas jouer a gauche
	if (col - turn > 0) {
		int gg = 1, gd = 1;
		// Gauche puis gauche
		if (col-turn-turn-1 > 0) {
			if (dynamic[IDX(turn+2, col-turn-turn-1)] == 0)
				dynamic[IDX(turn+2, col-turn-turn-1)] = eval(turn+2, col-turn-turn-1);

			gg = dynamic[IDX(turn+2, col-turn-turn-1)];
		}

		// Gauche puis droite
		if (col+1 <= MAX) {
			if (dynamic[IDX(turn+2, col+1)] == 0)
				dynamic[IDX(turn+2, col+1)] = eval(turn+2, col+1);
			
			gd = dynamic[IDX(turn+2, col+1)];
			
		}

		if (gg == gd == 1) {
			//cout << "victoire a gauche" << endl;
			return 1;
		}
	}

	// Cas jouer a droite
	if (col + turn <= MAX) {
		int dg = 1, dd = 1;
		// Gauche puis gauche
		if (col-1 > 0) {
			if (dynamic[IDX(turn+2, col-1)] == 0)
				dynamic[IDX(turn+2, col-1)] = eval(turn+2, col-1);

			dg = dynamic[IDX(turn+2, col-1)];
		}

		// Gauche puis droite
		if (col+turn+turn+1 <= MAX) {
			if (dynamic[IDX(turn+2, col+turn+turn+1)] == 0)
				dynamic[IDX(turn+2, col+turn+turn+1)] = eval(turn+2, col+turn+turn+1);
			
			dd = dynamic[IDX(turn+2, col+turn+turn+1)];
		}

		if (dg == dd == 1) {
			//cout << "victoire a droite" << endl;
			return 1;
		}
	}

	return 2;
}

bool possible (int turn, int col) {
	//cout << "possible: " << turn << " " << col << ": ";
	if (col - turn <= 0 && col + turn > MAX) {
		//cout << "False" << endl;
		return false;
	} else {
		//cout << "True" << endl;
		return true;
	}
}