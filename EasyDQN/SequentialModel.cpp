#include <iostream>
#include "Layer.cpp"
#include <vector>

using namespace std;
class SequentialModel {

private:
	std::vector<Layer*> layers;

	double calculate(double currentLayer[]) {

		for (int x = 0;x < sizeof(layers) - 1; x++) {
			int numNodes = layers[x + 1]->getWeights().size();
			std::vector<double> nextLayer(numNodes);
			std::fill(nextLayer.begin(), nextLayer.end(), 0.0);

			int counter = 0;
			for (double y : layers[x+1]->getWeights()) {
				for (int z = 0; z < sizeof(currentLayer); z++) {
					
					nextLayer[counter] = y* currentLayer[z];
				}
				counter++;
			}

			//fix
			for (int i = 0; i < numNodes; i++) {
				currentLayer[i] = nextLayer[i];
			}

		}
	}
public:
	SequentialModel() {

	};

	void add(Layer* layer) {
		this->layers.push_back(layer);
	};

	int predict(double nodes[]) {
		//check that input equals input layer nodes

		if (sizeof(nodes) == sizeof(layers[0]) ){
			
		}
		else {
			return NULL;
		}

	}
};