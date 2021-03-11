#include "CComplexVector1.h"

CComplexVector1 operator+(const CComplexVector1& left, const CComplexVector& right) {
	CComplexVector1 a(std::max(left.vecsize, CComplexVector1(right).vecsize));
	std::copy(left.data, left.data + left.vecsize, a.data);
	a += right;
	return a;
}

CComplexVector1 operator-(const CComplexVector1& left, const CComplexVector& right) {
	CComplexVector1 a(std::max(left.vecsize, CComplexVector1(right).vecsize));
	std::copy(left.data, left.data + left.vecsize, a.data);
	a -= right;
	return a;
}

int CComplexVector1::output(const char* FileName) {
	for (int i = 0; i < vecsize; i++) {
		if (data[i].im > 0) {
			std::cout << data[i].re << "+" << data[i].im << "i" << " ";
		}
		else if (data[i].im < 0) {
			std::cout << data[i].re << data[i].im << "i" << " ";
		}
		else {
			std::cout << data[i].re << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
