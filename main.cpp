#include <stdio.h>
#include <iostream>
#include <Windows.h>

#include <list>

int main() {
	std::list<const char*> stationName = {
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho"
	};
	std::cout << "1970�N�̎R����w�ꗗ" << std::endl;
	for (auto& name : stationName) {
		std::cout << name << std::endl;
	}
	std::cout << "\n" << std::endl;

	auto findStationNameIterator = std::find(stationName.begin(), stationName.end(), "Nippori");
	findStationNameIterator++;
	stationName.insert(findStationNameIterator, "Nishi-nippori");

	std::cout << "2019�N�̎R����w�ꗗ" << std::endl;
	for (auto& name : stationName) {
		std::cout << name << std::endl;
	}
	std::cout << "\n" << std::endl;

	findStationNameIterator = std::find(stationName.begin(), stationName.end(), "Shinagawa");
	findStationNameIterator++;
	findStationNameIterator = stationName.insert(findStationNameIterator, "TakanawaGateway");
	std::cout << "2022�N�̎R����w�ꗗ" << std::endl;
	for (auto& name : stationName) {
		std::cout << name << std::endl;
	}
	return 0;
}