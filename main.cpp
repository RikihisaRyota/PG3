#include <iostream>

#include <chrono>
#include <string>

int main() {
	std::string str(1000000, 'a');
	std::chrono::system_clock::time_point waitTime = std::chrono::system_clock::now();
	
	std::string copy = str;
	std::chrono::microseconds elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - waitTime);
	std::cout << elapsedTime.count() << std::endl;

	waitTime = std::chrono::system_clock::now();
	std::string move = std::move(str);
	elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - waitTime);
	std::cout << elapsedTime.count() << std::endl;
	return 0;
}