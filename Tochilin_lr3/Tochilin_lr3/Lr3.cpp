#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Lr3.h"

using namespace std;

StartCity::StartCity(string city) {
	this->city = city;
}

EndCity::EndCity(string city, int price) {
	this->city = city;
	this->price = price;
}

DijkstraAlgorithm::DijkstraAlgorithm(string path) {
	ifstream file(path);
	if (file.is_open()) {
		std::string city1, city2, price1, price2;

		while (getline(file, city1, ';'))
		{
			getline(file, city2, ';');
			getline(file, price1, ';');
			getline(file, price2, '\n');
			if (price1 != "N/A") {
				addEdge(city1, city2, stoi(price1));
			}
			if (price2 != "N/A") {
				addEdge(city2, city1, stoi(price2));
			}
		}
	}
	file.close();
	for (size_t i = 0; i < cities.size(); i++) {
		prices.push_back(INT_MAX);
		marks.push_back(false);
	}
}

void DijkstraAlgorithm::addEdge(string city1, string city2, int price) {
	bool isExists = false;
	int city1Pos = getCityPos(city1);
	int city2Pos = getCityPos(city2);
	if (city1Pos == -1) {
		StartCity* start = new StartCity(city1);
		cities.push_back(start);
		city1Pos = cities.size() - 1;
	}
	if (city2Pos == -1) {
		StartCity* start = new StartCity(city2);
		cities.push_back(start);
	}
	EndCity* end = new EndCity(city2, price);
	cities[city1Pos]->endCities.push_back(end);
}

int DijkstraAlgorithm::getCityPos(string city) {
	if (cities.size() == 0) {
		return -1;
	}
	size_t cityPos = 0;
	while (cities[cityPos]->city != city) {
		cityPos += 1;
		if (cityPos == cities.size()) {
			return -1;
		}
	}
	return cityPos;
}

void DijkstraAlgorithm::clear() {
	for (size_t i = 0; i < cities.size(); i++) {
		prices[i] = INT_MAX;
		marks[i] = false;
	}
}

int DijkstraAlgorithm::getMinPrice(string city1, string city2) {
	int city1Pos = getCityPos(city1);
	int city2Pos = getCityPos(city2);
	if (city1Pos == -1 || city2Pos == -1) {
		return -1;
	}
	if (prices[city1Pos] == 0) {
		return prices[city2Pos];
	}
	clear();
	prices[city1Pos] = 0;
	for (size_t i = 0; i < cities.size(); i++) {
		int curr = -1;
		for (size_t j = 0; j < cities.size(); j++) {
			if (!marks[j] && (curr == -1 || prices[j] < prices[curr])) {
				curr = j;
			}
		}
		if (curr == -1) {
			continue;
		}
		if (prices[curr] == INT_MAX) {
			break;
		}
		marks[curr] = true;
		for (size_t j = 0; j < cities[curr]->endCities.size(); j++) {
			size_t endCityPos = 0;
			while (cities[endCityPos]->city != cities[curr]->endCities[j]->city) {
				endCityPos += 1;
			}
			if (prices[curr] + cities[curr]->endCities[j]->price < prices[endCityPos]) {
				prices[endCityPos] = prices[curr] + cities[curr]->endCities[j]->price;
			}
		}
	}
	if (prices[city2Pos] == INT_MAX) {
		return -1;
	}
	return prices[city2Pos];
}