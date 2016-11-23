#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float neuron(float input, float weight);
float *neuron_layer(float input[], int nNeuron, float mNeuron[]);
float *input_layer(float input[], int nNeuron, float mNeuron[]);

int main() {

	/* A neural network consists of layers of neuron which are connected to each subsiquent layer and recieve input from each preceeding layer. The most common connection configuration results in each neuron being connected to each and every neuron in the next layer.
Let r_n be the number of neuron in the nth layer. Then each neuron in the nth layer takes r_(n-1) inputs and gives r_(n+1) outputs. */
	float a[] = { 1,1};
	float b[] ={1,1};
	float c[] = {1,1};
	
	float *output = neuron_layer(input_layer(a, 2, b) ,2,c);
	for (int i=0; i<2; i++) printf("%lf\n", *(output + i));
	return 0;

}

float neuron(float input, float weight) {
	return (input * weight);
}

float *input_layer(float input[], int nNeuron, float mNeuron[]) {
	float output[nNeuron];
	for (int i=0; i<nNeuron; i++) {
		output[i] = neuron(input[i], mNeuron[i]);
	}
	return output;
}

float *neuron_layer(float input[], int nNeuron, float mNeuron[]) {
	float output[nNeuron];
	float intsum = 0;
	for (int i=0; i<(sizeof(input)/sizeof(input[0])); i++) {
		intsum += input[i];
	}

	for (int i=0; i<nNeuron; i++) {
		output[i] = neuron(intsum, mNeuron[i]);
	}
	
	return output;
}
