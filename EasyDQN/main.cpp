#include <iostream>
#include "SequentialModel.cpp"

using namespace std;

int main() {
    
    int layers[] = { 2,3,2 };
    int size = sizeof(layers) / sizeof(layers[0]);
    SequentialModel* model = new SequentialModel(layers, size);

    double input[] = { 2.0, 5.0 };
    cout << model->predict(input) << endl;

    /*
    model.train(inputs, outputs, rewards);

    model.save("model.txt");
    model.load("model.txt");

    int input;
    int output = model.predict(input);*/
}