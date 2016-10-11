#include"Dict.h"

using namespace std;

Vec::Vec(vector<float> data)
{
	if (data.size() != SIZE)
		throw exception("Unequal Size");
	this->data = data;
}

Vec::Vec()
{
	data = vector<float>(SIZE, 0);
}

Vec & Vec::operator=(const Vec& other)
{
	this->data = other.data;
	return *this;
}

string Vec::toString()
{
	string s;
	for (float f : data) {
		s += to_string(f);
	}
	return s;
}

Vec Vec::operator+(const Vec & other)
{
	Vec vec;
	for (int i = 0; i <SIZE; i++) {
		vec.data[i] = this->data[i] + this->data[i];
	}
	return vec;
}

Vec Vec::operator/(float other)
{
	Vec vec;
	for (int i = 0; i < SIZE; i++) {
		vec.data[i] /= other;
	}
	return vec;
}

void Vec::operator+=(const Vec & other)
{
	for (int i = 0; i < SIZE; ++i) {
		this->data[i] += other.data[i];
	}
}

void Vec::operator/=(float other)
{
	for (int i = 0; i < SIZE; i++) {
		data[i] /= other;
	}
}
