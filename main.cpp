#include <iostream>
#include <stdio.h>
#include <typeinfo>

template <typename Type>
Type Min(Type a, Type b) {
	return a > b ? b : a;
}

template <typename Type>
void printMin(Type a) {
	std::cout << typeid(a).name() << ":" << a << std::endl;
}

template <>
void printMin<char>(char a) {
	printf_s("•¶Žš—ñˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ");
}


int main() {
	printMin(Min<int>(1, 2));
	printMin(Min<float>(1.0f, 2.0f));
	printMin(Min<double>(static_cast<double>(1.0f), static_cast<double>(2.0f)));
	printMin(Min<char>('a', 'b'));
	return 0;
}