#include <stdio.h>
#include <vector>

class Fruit {
public:
	virtual void GetFruitType();
protected:
	const char* name_;
};

class Apple : public Fruit {
public:
	Apple(const char* name);
	void GetFruitType() override;
};

class Orange :public Fruit {
public:
	Orange(const char* name);
	void GetFruitType() override;
	
};


int main() {
	const size_t kFruitSize = 3;
	std::vector<Fruit*> fruits;

	// 生成
	Apple* apple_0 = new Apple("王林");
	fruits.emplace_back(apple_0);
	Apple* apple_1 = new Apple("つがる");
	fruits.emplace_back(apple_1);
	Orange* orange = new Orange("ブラットオレンジ");
	fruits.emplace_back(orange);

	for (auto& fruit : fruits) {
		fruit->GetFruitType();
	}

	// 破棄
	for (size_t i = 0; i < kFruitSize;i++) {
		delete fruits.at(i);
	}
	return 0;
}

void Fruit::GetFruitType() {
	printf("GetFruitType:%s\n", name_);
}

Apple::Apple(const char* name) {
	name_ = name;
}

void Apple::GetFruitType() {
	printf("%sはリンゴの品種である\n", name_);
	printf("旬は秋から冬にかけてです");
}


Orange::Orange(const char* name) {
	name_ = name;
}

void Orange::GetFruitType() {
	printf("%sはオレンジの品種である\n", name_);
	printf("旬は春です");
}
