#include<iostream>
#include<fstream>

#include "Dict.h"
#include "Vec.h"
#include "Abstract.h"

using namespace std;

const string CANON_FOLDER = "/scratch2/jsybran/medline-canon-labeled/";

const string OUTPUT_FOLDER = "/scratch2/jsybran/medline-vectors/";

const string VECTOR_FILE = "/scratch2/jsybran/medline-model/fastTextSkipgramModel.vec";

const int NUM_CANON_FILES = 9;

string getCanonFilePath(int id) {
	return CANON_FOLDER + "labeled" + to_string(id);
}

string getOutputFilePath(int id) {
	return OUTPUT_FOLDER + "vectors" + to_string(id);
}

int main() {

	Dict wordDict(VECTOR_FILE);

	for (int i = 0; i < NUM_CANON_FILES; i++) {
		fstream canonFile = fstream(getCanonFilePath(i),ios::in);
		fstream outputFile = fstream(getOutputFilePath(i), ios::out);
		string canonLine;

		while (getline(canonFile,canonLine)) {
			if (canonLine.size() > 0) {
				Abstract abs = Abstract(canonLine, &wordDict);
				outputFile << abs.toString() << endl;
			}
		}
		outputFile.close();
		canonFile.close();
	}

	return 0;
}