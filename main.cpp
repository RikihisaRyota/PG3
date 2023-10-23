#include <stdio.h>
#include <vector>

struct Vector2 {
	float x;
	float y;
};

class Enemy {
public:
	virtual void Attack() = 0;
	virtual void Move() = 0;
protected:
	Vector2 position_;
};

class Apple : public Enemy {
public:
	void Attack() override;
	void Move() override;
};
void Apple::Attack() {
	printf("AppleAttack!\n");
}
void Apple::Move() {
	position_.x += 1.0f;
	printf("ApplePosition\nx:%.1f,y:%.1f\n",position_.x,position_.y);
}

class Orange :public Enemy {
public:
	void Attack() override;
	void Move() override;
};
void Orange::Attack() {
	printf("OrangeAttack!\n");
}
void Orange::Move() {
	position_.x += 5.0f;
	printf("OrangePosition\nx:%.1f,y:%.1f\n", position_.x, position_.y);
}


int main() {
	const size_t kEnemySize = 3;
	std::vector<Enemy*> enemies;

	// 生成
	for (size_t i = 0; i < kEnemySize; i++) {
		if (i < 1) {
			Apple* apple=new Apple();
			enemies.emplace_back(apple);
		}
		else {
			Orange* orange = new Orange();
			enemies.emplace_back(orange);
		}
	}

	// 移動
	printf("EnemyMove\n");
	for (auto& enemy : enemies) {
		enemy->Move();
	}
	printf("EnemyAttack\n");
	// 攻撃
	for (auto& enemy : enemies) {
		enemy->Attack();
	}

	// 破棄
	for (size_t i = 0; i < enemies.size();i++) {
		delete enemies.at(i);
	}
	return 0;
}


