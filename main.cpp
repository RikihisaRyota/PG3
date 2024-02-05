#include <stdio.h>

#include <string>

int main() {
	std::string str(1000000, 'a');
	std::string copy = str;
	std::string move = std::move(str);
	return 0;
}