#include <stdio.h>
#include <vector>

class IShape {
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
};

class Circle :public IShape {
public:
	Circle(float radius) :radius_(radius) {}
	void Size() override;
	void Draw() override;
private:
	float size_;
	float radius_;
};

class Rectangle :public IShape {
public:
	Rectangle(float width, float height):width_(width),height_(height) {}
	void Size() override;
	void Draw() override;
private:
	float size_;
	float width_;
	float height_;
};

int main() {
	const size_t kShape = 2;
	IShape* shape[kShape];
	shape[0] = new Circle(10.0f);
	shape[1] = new Rectangle(10.0f,20.0f);

	for (size_t i = 0; i < kShape; i++) {
		shape[i]->Size();
		shape[i]->Draw();
	}

	for (size_t i = 0; i < kShape; i++) {
		delete shape[i];
	}

	return 0;
}

void Circle::Size() {
	size_ = radius_ * radius_ * 3.14f;
}

void Circle::Draw() {
	printf("size:%f\n", size_);
}

void Rectangle::Size() {
	size_ = height_ * width_;
}

void Rectangle::Draw() {
	printf("size:%f\n", size_);
}
