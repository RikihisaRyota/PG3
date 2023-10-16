#include "Enemy.h"

#include <stdio.h>

void (Enemy::* Enemy::sStatePatternTable[])() = {
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::River
};

void Enemy::Update() {
	while (true) {
		int key;
		printf("接近:1,攻撃2,離脱3\n");
		scanf_s("%d", &key);
		while (key < 0 ||
			key > static_cast<size_t>(State::kCount)) {
			printf("1~3の間で選択してください\n");
			printf("接近:1,攻撃2,離脱3\n");
			scanf_s("%d", &key);
		}
		switch (key-1) {
		case static_cast<size_t>(Enemy::State::kApproach):
			(this->*sStatePatternTable[static_cast<size_t>(State::kApproach)])();
			break;
		case static_cast<size_t>(Enemy::State::kShoot):
			(this->*sStatePatternTable[static_cast<size_t>(State::kShoot)])();
			break;
		case static_cast<size_t>(Enemy::State::kRiver):
			(this->*sStatePatternTable[static_cast<size_t>(State::kRiver)])();
			break;
		}
	}
}

void Enemy::Approach() {
	printf("接近!\n");
}

void Enemy::Shoot() {
	printf("射撃!\n");
}

void Enemy::River() {
	printf("離脱!\n");
}
