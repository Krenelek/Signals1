// Fourier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine.h"
#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>
using namespace std;
const double pi2 = 4 * acos(0.0);
vector<complex<double>> sin_generator(double freq, double Fs, int size)
{
    vector <complex<double>> output = vector<complex<double>>(size, 0);
    for (int i = 0; i < size; i++)
    {
        output[i] = sin(pi2*i*freq/Fs);
    }
    return output;
}
void write_vector(vector<double> signal)
{
    for (int i = 0; i < signal.size(); i++)
    {
        cout << signal[i] << "\t";
    }
    cout << endl;
}
int main()
{
    cout << setprecision(2) << fixed;
    Engine xd(32);
    cout << "xd" << endl;
    //xd.show_matrix_d();
    
    /*vector<complex<double>> bu = { 1,1,1,1,1,1,1,1};
    bu = xd.window_fuction(bu);
    for (int i = 0; i < bu.size(); i++) 
    {
        cout << bu[i] << "\t";
    }*/
    //vector<double> b = { 1,0 };
    //a = xd.convolution(a,b);
    
    int a = 1750;
    vector <complex<double>> smth = xd.fft(sin_generator(a, 44100, 8192));
    //vector <complex<double>> smth = xd.fft(vector<complex<double>>(32, 1));
    cout << smth.size() <<  endl;
    //cout << smth[209] << endl;
    /*for (int i = 0; i < smth.size(); i++)
    {
        cout << smth[i] << endl;
    }*/
    //smth = xd.dft(sin_generator(a, 44100, 512));
    cout << smth.size() << endl;
    /*for (int i = 0; i < smth.size(); i++)
    {
        cout << smth[i] << endl;
    }*/
    cout << smth.size() << endl;
    write_vector(xd.band_freq_generator(10, 2));
    auto boiii=(xd.energy_in_bands_log_scale(smth,2));
    //auto boiii = (xd.energy_in_bands_log_scale(xd.dft(bu), 1));
    for (int i = 0; i < boiii.size(); i++)
    {
        cout << boiii[i] << "\t";
    }
}

