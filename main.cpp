#include <stdio.h>
#include <vector>

class Fruit {
public:
	virtual void Name();
protected:
	const char* name_;
};

class Apple : public Fruit {
public:
	Apple(const char* name);
	void Name() override;
};

class Orange :public Fruit {
public:
	Orange(const char* name);
	void Name() override;
};


int main() {
	const size_t kFruitSize = 3;
	std::vector<Fruit*> fruits;

	// 生成
	for (size_t i = 0; i < kFruitSize; i++) {
		if (i < 1) {
			Apple* apple=new Apple("Apple");
			fruits.emplace_back(apple);
		}
		else {
			Orange* orange = new Orange("Orange");
			fruits.emplace_back(orange);
		}
	}

	for (auto& fruit : fruits) {
		fruit->Name();
	}

	// 破棄
	for (size_t i = 0; i < kFruitSize;i++) {
		delete fruits.at(i);
	}
	return 0;
}

void Fruit::Name() {
	printf("Name:%s\n", name_);
}

Apple::Apple(const char* name) {
	name_ = name;
}

void Apple::Name() {
	printf("Name:%s\n", name_);
}


Orange::Orange(const char* name) {
	name_ = name;
}

void Orange::Name() {
	printf("Name:%s\n", name_);
}
