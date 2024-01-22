#include <iostream>

#include <thread>
#include <condition_variable>
#include <mutex>

#include <string>
#include <fstream>
#include <sstream>

#include <queue>

static const int Width = 26;
static const int Height = 12;

int main() {
	std::mutex mutex;
	std::condition_variable condition;
	bool exit = false;
	bool isLoad = false;

	std::ifstream input_csv("map.csv");
	std::vector<int> vector{};
	std::string get_line;
	std::string get_index;
	std::thread th([&]() {
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		std::unique_lock <std::mutex> uniqueLock(mutex);
		while (std::getline(input_csv, get_line)) {
			std::istringstream stream(get_line);
			while (std::getline(stream, get_index, ',')) {
				vector.emplace_back(std::stoi(get_index));
			}
		}
		condition.wait(uniqueLock);
		isLoad = true;
		});

	while (true) {
		condition.notify_all();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "NowLoading" << std::endl;
		if (isLoad) {
			for (int y = 0; y < Height; y++) {
				for (int x = 0; x < Width; x++) {
					std::cout << vector.at(y * Width + x) << "";
				}
				std::cout << "\n";
			}
			break;
		}
	}

	exit = true;
	th.join();
	return 0;
}