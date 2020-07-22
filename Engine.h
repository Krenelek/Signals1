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
	vector<double> circular_convolution(vector<double> signal, vector<double> filter);
	double energy_log_scale(vector<double> signal);//nie wiem czy potrzebny bo WAV jest w skali liniowej, ale to nie znaczy ¿e wyra¿a ju¿ poziom cisnienia
	vector<double> filter_generator(int f1, int f2);
	vector<double> third_freq_generator(int octaves);
private:
	const double pi2 = 4 * acos(0.0);
	vector<double> tab;
	int size;
	vector<vector<complex<double>>> matrix;
};

