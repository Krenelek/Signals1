#pragma once
using namespace std;
#include <iostream>
#include <complex>
#include <vector>

class Engine
{
public:
	vector<complex<double>> fft(vector<complex<double>> input);	
	//juz dla wszystkich
	//poprawka jest prosta - napisaæ j¹, do tego symetria binarna
	vector<complex<double>> ifft(vector<complex<double>> input);
	//matrix inversion
	vector<complex<double>> dft(vector<complex<double>> input);
	//potrzebna poprawka ze wzgledu na generowanie non stop macierzy przejscia niepotrzebnie, jakis if
	vector<complex<double>> idft(vector<complex<double>> input);
	Engine(int _size);
	void show_matrix_d();
	vector<double> convolution(vector<double> signal, vector<double> filter);
	vector<double> circular_convolution(vector<double> signal, vector<double> filter);
	double energy_log_scale(vector<complex<double>> signal);
	//nie wiem czy potrzebny bo WAV jest w skali liniowej, ale to nie znaczy ¿e wyra¿a ju¿ poziom cisnienia
	vector<double> filter_generator(int f1, int f2);
	vector<double> third_freq_generator(int octaves);
	//down & up sampling
private:
	const double pi2 = 4 * acos(0.0);
	vector<double> tab;
	int size;
	vector<vector<complex<double>>> matrix;
	vector<vector<complex<double>>> imatrix;
};

