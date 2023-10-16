#include <stdio.h>

#include "Comparison.h"

int main() {
	Comparison<int,int,int> int_0(10, 20);
	Comparison<int,float,float> int_1(10, 20.0f);
	Comparison<int,double,double> int_2(10, 20.0);
	Comparison<float,float,float> float_0(1.0f, 2.0f);
	Comparison<float,double,double> float_1(1.0f, 2.0);
	Comparison<double,double,double> double_0(5.0, 4.0);

	auto a = int_1.Min();
	printf("%d\n", int_0.Min());
	printf("%f\n", int_1.Min());
	printf("%lf\n", int_2.Min());
	printf("%f\n", float_0.Min());
	printf("%f\n", float_1.Min());
	printf("%lf\n", double_0.Min());
	return 0;
}