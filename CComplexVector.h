#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <string>
#include <exception>

struct CComplexNumber {
	double re;
	double im;
	CComplexNumber(double re = 0, double im = 0);
	CComplexNumber &operator+=(const CComplexNumber &right);
	CComplexNumber operator+(const CComplexNumber &right) const;
	CComplexNumber &operator-=(const CComplexNumber &right);
	CComplexNumber operator-(const CComplexNumber &right) const;
	CComplexNumber &operator*=(const CComplexNumber &right);
	CComplexNumber operator*(const CComplexNumber &right) const;
	CComplexNumber &operator/=(const CComplexNumber &right);
	CComplexNumber operator/(const CComplexNumber &right) const;
};

class CComplexVector {
public:
	CComplexVector(int size);
	CComplexVector(const CComplexVector &other);
	CComplexVector(CComplexVector &&other) noexcept;
	~CComplexVector();
	int size() const;
	CComplexVector &operator=(const CComplexVector &other);
	CComplexVector &operator=(CComplexVector &&other) noexcept;
	CComplexNumber &operator[](int i);
	const CComplexNumber &operator[](int i) const;
	CComplexVector &operator+=(const CComplexVector &right);
	CComplexVector &operator-=(const CComplexVector &right);
	friend CComplexNumber operator*(const CComplexVector& left, const CComplexVector& right);

	virtual int output(const char* FileName = nullptr) = 0;
	virtual void setFilename(const char* FileName) = 0;
	virtual const char* getFilename() const = 0;

protected:
	CComplexNumber *data = nullptr;
	char* FileName = nullptr;
	int vecsize = 0;
};
