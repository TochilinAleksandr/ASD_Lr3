#pragma once
#include <string>
#include <vector>

using namespace std;

class EndCity {
public:
	string city;
	int price;
	EndCity(string, int);
};

class StartCity {
public:
	string city;
	vector<EndCity*> endCities;
	StartCity(string);
};

class DijkstraAlgorithm {
	vector<StartCity*> cities;
	vector<int> prices;
	vector<bool> marks;
	void addEdge(string, string, int);
	int getCityPos(string);
	void clear();
public:
	DijkstraAlgorithm(string);
	int getMinPrice(string, string);
};