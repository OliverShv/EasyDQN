#include <iostream>
#include "Layer.cpp"
#include <vector>

using namespace std;
class SequentialModel {

private:
	vector<Layer> layers;

	vector<double> calculate(double input[]) {
		cout << "calculate" << endl;
		int numElements = sizeof(input) / sizeof(input[0]); // compute the number of elements in the array
		vector<double> currentLayer(input, input + numElements);

		//Go through each layer
		for (int x = 1; x < layers.size(); x++) {
			//Create a vector for the dot product of each node with the weights and previous layer nodes
			int numNodes = layers[x].getWeights().size();
			vector<double> nextLayer(numNodes);
			fill(nextLayer.begin(), nextLayer.end(), 0.0);
			//Go through the math between the current values and new next layer
			int counter = 0;
			// the output on each x+1 layer is each node of layer x multiplied by the weight for that relationship
			for (vector<double> y : layers[x].getWeights()) {
				for (int z = 0; z < currentLayer.size(); z++) {
					
					nextLayer[counter] += y[z]* currentLayer[z];
				}
				counter++;
			}

			for (double a : nextLayer) {
				cout << a << endl;
			}

			currentLayer = nextLayer;

		}

		return currentLayer;
	}
public:
	SequentialModel(int layers[], int size) {
		//Configure all layers

		add(Layer(layers[0]));
		for (int x = 1; x < size; x++) {
			add(Layer(layers[x],layers[x-1]));
		}
	};

	void add(Layer layer) {
		this->layers.push_back(layer);
	};

	int predict(double nodes[]) {
		//check that input equals input layer nodes

		cout << "predict" << endl;
		vector<double> result = calculate(nodes);
		cout << result.size() << endl;
		for (double a : result) {
			cout << a << endl;
		}
		
		
		int index = 0;
		double highest = result[0];
		for (int x = 1; x < result.size(); x++) {
			if (result[x] > highest) {
				index = 1;
			}
		}
		
		return index;
	}
};