#include <stdio.h>

#include "Enemy.h"

int main() {
	Enemy* enemy = new Enemy();
	enemy->Update();
	delete enemy;
	return 0;
}