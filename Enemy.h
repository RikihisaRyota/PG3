#pragma once
class Enemy {
public:
	enum class State {
		kApproach,
		kShoot,
		kRiver,

		kCount,
	};
public:
	void Update();
private:
	void Approach();
	void Shoot();
	void River();
	static void (Enemy::* sStatePatternTable[])();
};

