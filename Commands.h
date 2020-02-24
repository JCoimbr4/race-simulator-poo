#pragma once
#include <string>
using namespace std;

struct query {
	string cmd;
	int numberOfArgs = 0;
};

bool queryValidation(string input, int mode);