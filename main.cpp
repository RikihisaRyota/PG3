#include <iostream>

#include <string>
#include <thread>

void Print(std::string string) {
	std::cout << string << std::endl;
}

int main() {
	std::thread th1(Print, "thread 1");
	th1.join();
	std::thread th2(Print, "thread 2");
	th2.join();
	std::thread th3(Print, "thread 3");
	th3.join();


	return 0;
}