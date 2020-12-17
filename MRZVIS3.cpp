#include "neural_network.h"

int main()
{
	setlocale(LC_ALL, "rus");
	std::vector<std::vector<double>> input = {{1,-1,-1,1,1,1,-1,1,-1 }};
	neural_network nn;
	nn.printReference();
	nn.setInput(input);
	nn.start();
}
