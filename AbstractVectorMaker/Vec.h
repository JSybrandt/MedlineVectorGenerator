#pragma once

#include <vector>
#include<exception>
#include<string>
#include<iostream>

using std::vector;
using std::string;

class Vec {
private:

	const int SIZE = 500;

	vector<float> data;

public:
	Vec(vector<float> data);
	Vec();
	Vec(const Vec&) = default;
	Vec& operator=(const Vec&);
	string toString();
	Vec operator+(const Vec& other);
	Vec operator/(float other);
	void operator+=(const Vec& other);
	void operator/=(float other);
};