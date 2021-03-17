#pragma once
#include "CComplexVector.h"

class CComplexVector1 : public CComplexVector {
public:
	using CComplexVector::CComplexVector;
	using CComplexVector::operator=;
	friend CComplexVector1 operator+(const CComplexVector1& right, const CComplexVector& left);
	friend CComplexVector1 operator-(const CComplexVector1& right, const CComplexVector& left);
	CComplexVector1() = default;
	CComplexVector1(const CComplexVector& r) : CComplexVector(r) {}
	CComplexVector1(CComplexVector&& r) noexcept : CComplexVector(std::move(r)) {}
	void setFilename(const char* FileName) override;
	const char* getFilename() const override;
	int output(const char* FileName = nullptr) override;
};
