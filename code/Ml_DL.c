// Activation function: ReLU
float relu(float x) {
	return x > 0.0F ? x : 0.0F;
}

/*Calculate layer 1. This layer calculates the value of each node of the first hidden layer. This requires the arrays "bias1" and "weight1" and the input_data */
float z1[HIDDEN_NODES];
for (int i = 0; i < HIDDEN_NODES; i++) {
    z1[i] = bias1[i];
    z1[i] += weight1[i][0] * input_data;
    z1[i] = relu(z1[i]);
}

/*Calculate layer 2. This layer calculates the value of each node of the second hidden layer. This requires the arrays "bias2" and "weight2" and the result array of the first hidden layer. */
float z2[HIDDEN_NODES];
for (int i = 0; i < HIDDEN_NODES; i++) {
    z2[i] = bias2[i];
    for (int j = 0; j < HIDDEN_NODES; j++) {
        z2[i] += weight2[j][i] * z1[j];
    }
    z2[i] = relu(z2[i]);
}

/*Calculate output. This layer calculates the output value. This requires the arrays "bias3" and "weight3" and the result array of the second hidden layer. This layer does not require the relu function. */
float y = bias3[0];
for (int i = 0; i < HIDDEN_NODES; i++) {
    y += weight3[0][i] * z2[i];
}

*output_data = y; // No activation function for the output layer

// the same but with cube.AI
n_batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
