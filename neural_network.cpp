//Автор : Киневич Т.О. группа : 821703
#include "neural_network.h"
#include <thread>
neural_network::neural_network() {
	a = 0.0000005;
	Err = 0;
	setReference();
	e = (double)1 / (double)reference.getHeight();
	FindE();
	Emax = 0.1;
	initializeWeights();
	FindE();
}

void neural_network::learn() {
}

void neural_network::initializeWeights() {
	Matrix Temp;
	Temp = reference;
	firstWeights = Temp * 0.5;
}

void neural_network::start() {
	Matrix Y1,Rez,Y2,Diff,TempMat;
	input.print();
	Y1 = input * firstWeights.Transposition();
	activate(Y1);
	Rez = Y1;
	do {
		Y2 = Rez * E;
		activate(Y2);
		Diff = Y2 - Rez;
		Rez = Y2;
		std::cout << Diff.square() << std::endl;
	} while(Diff.square() >= Emax);
	TempMat = findMat(Rez);
	std::cout << "Результат : " << std::endl;
	TempMat.print();
}

void neural_network::setReference() {
	std::vector<std::vector<double>> temp;
	temp.push_back({ 1,-1,1,-1,1,-1,1,-1,1 });
	temp.push_back({ -1,1,-1,1,1,1,-1,1,-1 });
	temp.push_back({ -1,-1,-1,1,1,1,-1,-1,-1 });
	temp.push_back({ -1,1,-1,-1,1,-1,-1,1,-1 });
	temp.push_back({ 1,1,1,-1,1,-1,1,1,1 });
	temp.push_back({ 1,-1,1,1,1,1,1,-1,1 });
	temp.push_back({ -1,-1,-1,-1,-1,-1,1,1,1 });
	temp.push_back({ 1,1,1,-1,-1,-1,-1,-1,-1 });
	temp.push_back({ 1,1,1,1,-1,1,1,1,1});
	reference.setData(temp);

}

void neural_network::activate(Matrix& Mat) {
	std::vector<std::vector<double>> Temp;
	Temp = Mat.getData();
	for (auto i = 0; i < Temp.size(); i++) {
		for (auto j = 0; j < Temp[i].size(); j++) {
			if (Temp[i][j] >= 0) {
			}
			else {
				Temp[i][j] = 0;
			}
		}
	}
	Mat.setData(Temp);
}

void neural_network::printReference() {
	Matrix TempMat;
	std::vector<std::vector<double>> Temp,Temp1;
	Temp = reference.getData();
	for (auto i = 0; i < Temp.size(); i++) {
		Temp1.push_back(Temp[i]);
		TempMat.setData(Temp1);
		TempMat.print();
		Temp1.clear();
	}
}

void neural_network::FindE() {
	std::vector<std::vector<double>> temp;
	temp.resize(reference.getHeight());
	for (auto i = 0; i < reference.getHeight(); i++) {
		temp[i].resize(reference.getHeight());
		for (auto j = 0; j < reference.getHeight(); j++) {
			if (i == j) {
				temp[i][j] = 1;
			}
			else {
				temp[i][j] = -e;
			}
		}
	}
	E.setData(temp);
}

void neural_network::setInput(std::vector<std::vector<double>>Input) {
	input.setData(Input);
}

Matrix neural_network::findMat(Matrix Mat) {
	double Max = 0;
	int num = 0;
	std::vector<std::vector<double>> Temp;
	std::vector<double> Temp1;
	Temp = Mat.getData();
	for (auto i = 0; i < Temp.size();i++) {
		for (auto j = 0; j < Temp[i].size();j++) {
			if (Temp[i][j] > Max) {
				num = j;
				Max = Temp[i][j];
			}
		}
	}
	Temp = reference.getData();
	Temp1 = Temp[num];
	Temp.clear();
	Temp.push_back(Temp1);
	Matrix TempMat;
	TempMat.setData(Temp);
	return TempMat;
}