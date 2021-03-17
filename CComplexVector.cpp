#include <cassert>
#include <algorithm>
#include "CComplexVector.h"

CComplexNumber::CComplexNumber(double re, double im) {
	this->re = re;
	this->im = im;
}

CComplexNumber& CComplexNumber::operator+=(const CComplexNumber& right) {
	re = re + right.re;
	im = im + right.im;
	return *this;
}

CComplexNumber CComplexNumber::operator+(const CComplexNumber& right) const {
	CComplexNumber a = *this;
	a += right;
	return a;
}

CComplexNumber& CComplexNumber::operator-=(const CComplexNumber& right) {
	re = re - right.re;
	im = im - right.im;
	return *this;
}

CComplexNumber CComplexNumber::operator-(const CComplexNumber& right) const {
	CComplexNumber a = *this;
	a -= right;
	return a;
}

CComplexNumber& CComplexNumber::operator*=(const CComplexNumber& right) {
	double re = this->re;
	double im = this->im;
	this->re = re * right.re - im * right.im;
	this->im = im * right.re + re * right.im;
	return *this;
}

CComplexNumber CComplexNumber::operator*(const CComplexNumber& right) const {
	CComplexNumber a = *this;
	a *= right;
	return a;
}

CComplexNumber& CComplexNumber::operator/=(const CComplexNumber& right) {
	double re = this->re;
	double im = this->im;
	this->re = (re * right.re + im * right.im) / (right.re * right.re + right.im * right.im);
	this->im = (im * right.re - re * right.im) / (right.re * right.re + right.im * right.im);
	return *this;
}

CComplexNumber CComplexNumber::operator/(const CComplexNumber& right) const {
	CComplexNumber a = *this;
	a /= right;
	return a;
}

CComplexVector::CComplexVector(int size) {
	this->vecsize = size;
	this->data = new CComplexNumber[size]();
}

CComplexVector::CComplexVector(const CComplexVector &other) {
	this->vecsize = other.vecsize;
	this->data = new CComplexNumber[vecsize]();
	std::copy(other.data, other.data + this->vecsize, this->data);
}

CComplexVector::CComplexVector(CComplexVector &&other) noexcept {
	this->vecsize = other.vecsize;
	this->data = other.data;
	other.vecsize = 0;
	other.data = nullptr;
}

CComplexVector::~CComplexVector() {
	delete[] this->FileName;
	delete[] this->data;
}

int CComplexVector::size() const {
	return this->vecsize;
}

CComplexVector &CComplexVector::operator=(const CComplexVector &other) {
	if (&other != this) {
		delete[] this->data;
		this->vecsize = other.vecsize;
		this->data = new CComplexNumber[vecsize]();
		std::copy(other.data, other.data + this->vecsize, this->data);
	}
	return *this;
}

CComplexVector &CComplexVector::operator=(CComplexVector &&other) noexcept {
	if (&other != this) {
		delete[] this->data;
		this->vecsize = other.vecsize;
		this->data = other.data;
		other.vecsize = 0;
		other.data = nullptr;
	}
	return *this;
}

CComplexNumber &CComplexVector::operator[](int i) {
	assert(i >= 0 && i < vecsize);
	return this->data[i];
}

const CComplexNumber &CComplexVector::operator[](int i) const {
	assert(i >= 0 && i < vecsize);
	return this->data[i];
}

CComplexVector &CComplexVector::operator+=(const CComplexVector &right) {
	for (int i = 0; i < std::min(this->vecsize, right.vecsize); i++) {
		this->data[i] += right[i];
	}
	return *this;
}

CComplexVector &CComplexVector::operator-=(const CComplexVector &right) {
	for (int i = 0; i < std::min(this->vecsize, right.vecsize); i++) {
		this->data[i] -= right[i];
	}
	return *this;
}

CComplexNumber operator*(const CComplexVector &left, const CComplexVector &right) {
	CComplexNumber num;
	for (int i = 0; i < std::min(left.size(), right.size()); i++) {
		num += left[i] * right[i];
	}
	return num;
}
