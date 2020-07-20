// Fourier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine.h"
#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
    cout << setprecision(2) << fixed;
    Engine xd(8);
    cout << "xd" << endl;
    xd.show_matrix_d();
    vector<double> a = { 1,1,1,1 };
    vector<double> b = { 1,0 };
    a = xd.convolution(a,b);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

    //jak zwracam pointer metod¹ to czy jest usuwana reszta popisanych rzeczy wektorem czy nie? jeœli nie to jak to usun¹æ potem?
}

