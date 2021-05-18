#include <iostream>
#include "Lr3.h"

using namespace std;

int main() {
	DijkstraAlgorithm* aviasales = new DijkstraAlgorithm("./aviasales.txt");
	cout << aviasales->getMinPrice("Moscow", "Irkutsck") << endl;
	cout << aviasales->getMinPrice("Moscow", "Chita") << endl;
	cout << aviasales->getMinPrice("Moscow", "Vladivostock") << endl;
	cout << aviasales->getMinPrice("Irkutsck", "Moscow") << endl;
	cout << aviasales->getMinPrice("Chita", "Moscow") << endl;
	cout << aviasales->getMinPrice("Vladivostock", "Moscow") << endl;
	return 0;
}