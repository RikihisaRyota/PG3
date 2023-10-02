#include <iostream>
#include <stdio.h>
#include <random>
#include <windows.h>

std::random_device rd;
// さいころを振る
int RollDice() {
	std::mt19937 mt(rd());
	return mt() % 6 + 1;
}
// 時間を指定して引数の関数を実行する
typedef void (*PFunc)(int a,int b);
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
	int userGuess = GetUserGuess();
	int diceResult = RollDice();

	PFunc result = Result;
	SetTime(result,3, diceResult , userGuess);

	return 0;
}