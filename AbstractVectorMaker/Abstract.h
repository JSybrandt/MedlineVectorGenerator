#pragma once

#include<string>
#include<sstream>
#include"Dict.h"
#include"Vec.h"

using std::string;
using std::stringstream;

class Abstract {
private:

	Dict* dict;
	vector<Vec> wordVecs;
	Vec vec;
	string key;

	const char delim = '|';

public:
	Abstract(string data, Dict* dict);

	Vec getVec();

	string toString();


};
