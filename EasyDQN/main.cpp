#include <iostream>
using namespace std;
#include "SequentialModel.cpp";
#include "HiddenLayer.cpp"
#include "InputLayer.cpp"
#include "OutputLayer.cpp"


int main() {

	SequentialModel* model = new SequentialModel();

	model->add(new InputLayer(2));
	model->add(new HiddenLayer(3));
	model->add(new OutputLayer(2));

	/*
	model.train(inputs, outputs, rewards);

	model.save("model.txt");
	model.load("model.txt");

	int input;
	int output = model.predict(input);*/

}