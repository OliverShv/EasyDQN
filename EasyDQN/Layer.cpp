#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Layer {

private:
	vector<vector<double>> weights;

public:
 
	Layer(int nodes, int previous_nodes){
		//record the number of nodes
		cout << "Layer" << endl;
		for (int x = 0; x < nodes; x++) {
			// seed the random number generator with the current time
			srand(time(NULL)+x*time(NULL));
			weights.push_back(vector<double>());
			for (int y = 0; y < previous_nodes; y++){

				// generate a random value between 0 and RAND_MAX
				int randomValue = rand();

				// scale the random value to a double between 0 and 1
				double randomDouble = static_cast<double>(randomValue) / RAND_MAX;
				cout << randomDouble << endl;
				//Add random value which is the intial weight of the node
				weights[x].push_back(randomDouble);
			}
		}
	};

	Layer(int nodes) {

	}

	std::vector<std::vector<double>> getWeights() {
		return this->weights;
	};

};