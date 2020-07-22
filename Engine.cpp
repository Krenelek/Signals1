#include "Engine.h"
using namespace std;
#include <iostream>
#include <complex>
#include <vector>

	Engine::Engine(int _size)
	{	
		
		size = _size;
		matrix=vector<vector<complex<double>>>(size);
		for (int i = 0; i < size; i++)
		{
			matrix[i] = vector<complex<double>>(size);
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = polar(1.0, pi2 * i * j/size);
			}
		}
		cout << "engine has been created" << endl;
	}
	vector<double> Engine::absdft(vector<double> input)
	{
		vector<complex<double>> complexoutput;
		vector<double> output;
		for (int i = 0; i < size; i++)
		{
			
			for (int j = 0; j < size; j++)
			{					
				complexoutput[i] =  matrix[j][i] * input[j];
			}
			complexoutput.push_back(0);
		}
		for (int i = 0; i < size; i++)
		{
			output[i] = abs(complexoutput[i]);
		}
		return output;

	}
	void Engine::show_matrix_d()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j] << "\t\t";
			}
			cout << endl << endl;
		}
	}
	//jak to jest z filtrami i ch dlugosciami w czestotliwosci
	//metoda okien czasowych srodkowoprzepustowy

	vector<double> Engine::convolution(vector<double> signal, vector<double> filter)
	{
		int size_filter = filter.size();
		int size_signal = signal.size();
		int shorter = 0;
		if (size_signal > size_filter)
		{
			shorter = size_filter;
			filter.resize(size_signal,0);
		}
		else
		{
			shorter = size_signal;
			signal.resize(size_signal, 0);
		}
		vector<double> output = vector<double>(signal.size(), 0);
		
		for (int i = 0; i < output.size(); i++)
		{
			for (int j = 0; j < i+1; j++)
			{
				output[i] = output[i] + filter[j] * signal[i-j];
			}
			for (int j = i+1; j < output.size(); j++)
			{
				output[i] = output[i] + filter[j] * signal[output.size()+i-j];
			}
			
		}
		return output;
	}
	double Engine::energy_log_scale(vector<double> signal)
	{
		double sum = 0;
		for (int i = 0; i < signal.size(); i++)
		{
			sum = sum + signal[i] * signal[i];
		}

		return log(sum);
	}
	vector<double> Engine::circular_convolution(vector<double> signal, vector<double> filter)
	{
		int size_filter = filter.size();
		int size_signal = signal.size();
		int shorter = 0;
		if (size_signal > size_filter)
		{
			shorter = size_filter;
		}
		else
		{
			shorter = size_signal;
		}
		int counter = 0;
		vector<double> output = vector<double>(size_signal + size_filter - 1, 0);

		for (int i = 0; i < output.size(); i++)
		{

			if (i < shorter) { counter++; }
			if (i > output.size() - shorter - 1) { counter--; }
			for (int j = 0; j < counter; j++)
			{
				output[i] = output[i] + filter[j] * signal[i - j];
				cout << output[i] << endl;
			}
			cout << endl;
		}
		return output;
	}
	vector<double> Engine::filter_generator(int f1, int f2)
	{
		//prewarping
		//bandpass
		//-3dB bandwidth

	}
	vector<double> Engine::third_freq_generator(int octaves)
	{
		vector<double> output = vector<double>(octaves*3+1, 16);
		double a = pow(2, (1 / 4));
		for (int i = 0; i < octaves* 3; i++)
		{
			output[i + 1] = output[i] * a;
		}
		return output;
	}

