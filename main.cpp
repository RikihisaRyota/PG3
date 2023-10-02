#include <functional>
#include <iostream>
#include <stdio.h>
#include <random>
#include <windows.h>

// 時間を指定して引数の関数を実行する
typedef void (*PFunc)(int a, int b);
void SetTime(PFunc func, int second, int diceResult, int userGuess) {
	Sleep(second * 1000);
	func(diceResult, userGuess);
}
// 奇数か偶数かを判別
void Result(int diceResult, int userGuess) {
	std::cout << "さいころの出目は " << diceResult;
	std::cout << " で";
	std::cout << (diceResult % 2 == 0 ? "偶数" : "奇数");
	std::cout << " です。" << std::endl;

	if ((diceResult % 2 == 0 && userGuess == 2) || (diceResult % 2 == 1 && userGuess == 1)) {
		std::cout << "当たり！" << std::endl;
	}
	else {
		std::cout << "はずれ..." << std::endl;
	}
}

// ユーザーに予測させる
int GetUserGuess() {
	int userGuess = 0;
	while (userGuess != 1 && userGuess != 2) {
		std::cout << "奇数か偶数か選択しenterを押してください" << std::endl;
		std::cout << "1 : 奇数, 2 : 偶数" << std::endl;
		std::cin >> userGuess;
	}
	return userGuess;
}


int main() {
	std::random_device rd;
	std::mt19937 mt(rd());

	int userGuess = GetUserGuess();
	std::function<int()> diceRoll = [&mt]() {
		return mt() % 6 + 1;
		};
	int diceResult = diceRoll();

	PFunc result = Result;
	SetTime(result, 3, diceResult, userGuess);

	return 0;
}