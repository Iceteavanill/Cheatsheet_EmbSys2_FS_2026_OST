void softmax(float* logits, float* prob) {
    // Calculate the sum of exponentials
    float sumOfExp = 0.0;
    for (size_t i = 0; i < NUM_OF_OUTPUT_NODES; ++i)
        sumOfExp += exp(logits[i]);
    // Calculate the probabilities
    for (size_t i = 0; i < NUM_OF_OUTPUT_NODES; ++i)
        prob[i] = exp(logits[i]) / sumOfExp;
}