#include <iostream>
#include "Layer.cpp";
using namespace std;

class HiddenLayer : public Layer {

private:

public:
	HiddenLayer(int nodes) : Layer(nodes) {};

};