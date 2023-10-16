#pragma once

#include <algorithm>
template <typename Type1, typename Type2, typename Type3>
class Comparison {
public:
	Comparison(Type1 a, Type2 b) : a_(a),b_(b){}
	Type3 Min() {
		if (a_ < b_) {
			return static_cast<Type3>(a_);
		}
		return static_cast<Type3>(b_);
	}	
private:
	Type1 a_;
	Type2 b_;
};

