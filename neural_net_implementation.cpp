//Made a neural net that takes three values 

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class trainingSet
{
public:
	int trainingInputs[4][3] = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}, {0, 1, 1}};
	int outputs[4] = {0, 1, 1, 0};
};

class neuron;

typedef vector<neuron> layer;
class neuron
{
public:

	vector<vector<int> > trainingInputs = { {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
	vector<float> trainingInputResults = {0, 0, 0, 0, 1, 1, 1, 1 };
	vector<float> inputWeights;
	
	void initWeights(){
		for(int i = 0; i < this->trainingInputs[0].size(); i++){
			inputWeights.push_back((float)rand()/(RAND_MAX+1) * (.5 - (-.5)) + (.5));
		}
	}

	void showWeights(){
	    for(int i=0; i < inputWeights.size(); i++){
			cout << inputWeights[i] << endl;
		}
	}

	float __sigmoid(float x){
		return 1 / (1 + exp(-x));
	}

	double __sigmoidDerivative(float x){
		return x * (1-x);
	}

	float think(vector<int> input){
		return __sigmoid(inner_product(input.begin(), input.end(), inputWeights.begin(), 0.));
	}

	void train(vector<vector<int>> trainingInputs, vector<float> trainingInputResults, int iterations){
		for(int j = 0; j < iterations; j++){
			vector<float> outputs;
			for ( int i = 0; i < trainingInputs.size(); i++ ){
				outputs.push_back(this->think(trainingInputs[i]));
			}

			vector<float> error;
			for( int i = 0; i < trainingInputResults.size(); i++) {
				error.push_back(trainingInputResults[i] - outputs[i]); 
			}

			vector<float> adjustedError;
			for( int i = 0; i < trainingInputResults.size(); i++){
				adjustedError.push_back(error[i] * __sigmoidDerivative(outputs[i]));
			}

			vector<float> adjustments;
			for( int i = 0; i < this->inputWeights.size(); i++){
				adjustments.push_back(inner_product(trainingInputs[i].begin(), trainingInputs[i].end(), adjustedError.begin(), 0.));
			}

			for( int i = 0; i < this->inputWeights.size(); i++){
				this->inputWeights[i] += adjustments[i];
			}
		}
	}
};

int main(){
	neuron neuron1;
	neuron1.initWeights();
	neuron1.train(neuron1.trainingInputs, neuron1.trainingInputResults, 10000);
	neuron1.showWeights();
	cout << neuron1.think({0, 0, 0}) << endl;
}