#include <iostream>

uint32_t CalcRecurrenceWage(uint32_t wage, uint32_t hours) {
	if (hours <= 0) {
		return wage;
	}
	return wage + CalcRecurrenceWage(wage * 2 - 50, hours - 1);
}

uint32_t CalcGenericWage(uint32_t wage, uint32_t hours) {
	if (hours <= 0) {
		return wage;
	}
	return wage + CalcGenericWage(wage,hours - 1);
}
int main() {
	const uint32_t kHours = 10 - 1;
	for (uint32_t i = 1; i < kHours; i++) {
	uint32_t recurrenceWage = CalcRecurrenceWage(100, i - 1);
	uint32_t genericWage = CalcGenericWage(1072, i - 1);
	std::wcout << i << "時間" << std::endl;
	std::wcout << "一般的な賃金体制:" << recurrenceWage << std::endl;
	std::wcout << "再帰的な賃金体制:" << genericWage << std::endl;
	}
	return 0;
}