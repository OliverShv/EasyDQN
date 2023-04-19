#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Layer {

protected:
	std::vector<double> weights;

public:
	Layer(int nodes) {
		//record the number of nodes

		for (int x; x < nodes; x++) {

			// seed the random number generator with the current time
			std::srand(std::time(nullptr));

			// generate a random value between 0 and RAND_MAX
			int randomValue = std::rand();

			// scale the random value to a double between 0 and 1
			double randomDouble = static_cast<double>(randomValue) / RAND_MAX;

			//Add random value which is the intial weight of the node
			weights.push_back(randomDouble);
		}
	};
	std::vector<double> getWeights() {
		return this->weights;
	};

};