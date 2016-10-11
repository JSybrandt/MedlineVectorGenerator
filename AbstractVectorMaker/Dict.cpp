#include"Dict.h"

using namespace std;
Dict::Dict(string file) {
	fstream dataFile = fstream(file, ios::in);
	string line;
	while (getline(dataFile,line)) {
		if (line.length() > 0) {
			stringstream s;
			s << line;
			string word;
			s >> word;
			vector<float> vectorData;
			float d;
			while (s >> d) {
				vectorData.push_back(d);
			}
			data[word] = Vec(vectorData);
		}
	}
	dataFile.close();
}

const Vec Dict::getVec(string word) {
	if (data.find(word) == data.end())
		return Vec();
	else
		return data[word];
}