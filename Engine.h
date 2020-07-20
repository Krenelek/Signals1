#pragma once
using namespace std;
#include <iostream>
#include <complex>
#include <vector>

class Engine
{
public:
	vector<double> absdft(vector<double> input);
	Engine(int _size);
	void show_matrix_d();
	vector<double> convolution(vector<double> signal, vector<double> filter);
	double energy_log_scale(vector<double> signal);
	vector<double> filter_generator(int f1, int f2);
	vector<int> third_freq_generator();
private:
	const double pi2 = 4 * acos(0.0);
	vector<double> tab;
	int size;
	vector<vector<complex<double>>> matrix;
};

