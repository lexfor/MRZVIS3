#pragma once
//#include "Neuron.h"
#include "Matrix.h"
#include <iostream>

class neural_network
{
private:
	Matrix reference;
	Matrix firstWeights;
	Matrix secondWeights;
	double a;
	double Err;
	double e;
	Matrix E;
	double Emax;
	Matrix input;
public:
	neural_network();
	void setReference();
	void initializeWeights();
	void learn();
	void start();
	void activate(Matrix& Mat);
	void FindE();
	void setInput(std::vector<std::vector<double>>);
	Matrix findMat(Matrix Mat);
	void printReference();
};

