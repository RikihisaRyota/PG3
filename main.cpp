#include <iostream>

int AddRecurrenceWage(int wage) {
	return wage * 2 - 50;
}

int AddGenericWage(int wage) {
	const int kWage = 1072;
	return wage += kWage;
}
int main() {
	const int kHours = 10;
	int recurrenceWage = 100;
	int genericWage = 0;
	for (int i = 0; i < kHours; i++) {
		std::wcout << i << "時間" << std::endl;
		std::wcout << "一般的な賃金体制:" << recurrenceWage << std::endl;
		std::wcout << "再帰的な賃金体制:" << genericWage << std::endl;

		recurrenceWage = AddRecurrenceWage(recurrenceWage);
		genericWage = AddGenericWage(genericWage);
	}
	return 0;
}