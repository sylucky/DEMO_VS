#pragma once
#include <iostream>
#include <vector>
#include <array>
#define LEN 4
using namespace std;

class vecDemo
{
public:
	vecDemo();
	~vecDemo();

	void printVar();
private:
	double d_var[LEN];
	vector<double> vec_var;
	array<double, LEN> arr_var;

};

