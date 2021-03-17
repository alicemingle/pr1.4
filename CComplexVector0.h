#pragma once
#include "CComplexVector.h"

class CComplexVector0 : public CComplexVector {
public:
	using CComplexVector::CComplexVector;
	using CComplexVector::operator=;
	friend CComplexVector0 operator+(const CComplexVector0& right, const CComplexVector& left);
	friend CComplexVector0 operator-(const CComplexVector0& right, const CComplexVector& left);
	CComplexVector0() = default;
	CComplexVector0(const CComplexVector& r) : CComplexVector(r) {}
	CComplexVector0(CComplexVector&& r) noexcept : CComplexVector(std::move(r)) {}
	void setFilename(const char* FileName) override;
	const char* getFilename() const override;
	int output(const char* FileName = nullptr) override;
};
