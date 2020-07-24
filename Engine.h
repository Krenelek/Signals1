#pragma once
using namespace std;
#include <iostream>
#include <complex>
#include <vector>

class Engine
{
public:
	vector<complex<double>> fft(vector<complex<double>> input);	
	// size!=2^n uzupe³nic poczatkiem
	vector<complex<double>> ifft(vector<complex<double>> input);
	//fft zmienic, dzielenie przez dlugosc
	vector<complex<double>> dft(vector<complex<double>> input);
	//potrzebna poprawka ze wzgledu na generowanie non stop macierzy przejscia niepotrzebnie, jakis if
	vector<complex<double>> idft(vector<complex<double>> input);
	//matrix inversion, dzielenie przez dlugosc
	Engine(int _size);
	void show_matrix_d();
	vector<double> convolution(vector<double> signal, vector<double> filter);
	vector<double> circular_convolution(vector<double> signal, vector<double> filter);
	vector<double> energy_in_thirds_log_scale(vector<complex<double>> signal);
	//nie wiem czy potrzebny bo WAV jest w skali liniowej, ale to nie znaczy ¿e wyra¿a ju¿ poziom cisnienia
	vector<double> third_freq_generator(int octaves);
private:
	vector<complex<double>> even_odd_decomposer(vector<complex<double>> input);
	vector<complex<double>> sub_fft(vector<complex<double>> input);
	const double pi2 = 4 * acos(0.0);
	vector<double> tab;
	int size;
	vector<vector<complex<double>>> matrix;
	vector<vector<complex<double>>> imatrix;
};

