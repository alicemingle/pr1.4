#include "CComplexVector0.h"

CComplexVector0 operator+(const CComplexVector0& left, const CComplexVector& right)  {
	CComplexVector0 a(std::max(left.vecsize, CComplexVector0(right).vecsize));
	std::copy(left.data, left.data + left.vecsize, a.data);
	a += right;
	return a;
}

CComplexVector0 operator-(const CComplexVector0& left, const CComplexVector& right) {
	CComplexVector0 a(std::max(left.vecsize, CComplexVector0(right).vecsize));
	std::copy(left.data, left.data + left.vecsize, a.data);
	a -= right;
	return a;
}

int CComplexVector0::output(const char* FileName) {
	if (FileName == nullptr) {
		std::cout << "Error occured while working with file!" << std::endl;
		return 1;
	}
	std::ofstream out(FileName, std::ios::app);
	for (int i = 0; i < vecsize; i++) {
		if (data[i].im > 0) {
			out << data[i].re << "+" << data[i].im << "i" << std::endl;
		}
		else if (data[i].im < 0) {
			out << data[i].re << data[i].im << "i" << std::endl;
		}
		else {
			out << data[i].re << std::endl;
		}
	}
	out << std::endl;
	out.close();
	return 0;
}
