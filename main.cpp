#include <stdio.h>

template <typename Type>
Type Min(Type a, Type b) {
	return a > b ? b : a;
}

template <>
char Min<char>(char a, char b) {
	printf_s("•¶Žš—ñˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ");
	return 0;
}

int main() {
	printf_s("int(1,2):%d\n", Min<int>(1, 2));
	printf_s("float(1.0f,2.0f):%f\n", Min<float>(1.0f, 2.0f));
	printf_s("double(1.0f,2.0f):%f\n", Min<double>(static_cast<double>(1.0f), static_cast<double>(2.0f)));
	printf_s("char(a,b):%f\n", Min<char>('a', 'b'));
	return 0;
}