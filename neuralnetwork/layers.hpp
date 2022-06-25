#ifndef LAYERS_H
#define LAYERS_H

#include <random>
#include "matrix.hpp"
#include "activations.hpp"


/* Abstract layer class */
class Layer{    
    public:
        virtual Matrix<float> feedforward(Matrix<float> input) = 0;
        virtual void print() = 0;
        virtual void saveToFile() = 0;

        virtual size_t getInputSize() = 0;
        virtual size_t getOutputSize() = 0;
        virtual Matrix<float> getWeights() = 0;

        virtual void setWeights(Matrix<float> newWeights) = 0;
        virtual void setActivation(activation_t act) = 0;
};


/* Fully connected layer */
class FCLayer : public Layer{
    private:
        Matrix<float> weights;
        activation_t activation;
        size_t inputSize, outputSize;
        bool bias = true;
    
    public:
        FCLayer(size_t inputLen, size_t outputLen, activation_t act, bool addBias=true);
        Matrix<float> feedforward(Matrix<float> input);
        void print();
        void saveToFile();

        size_t getInputSize();
        size_t getOutputSize();
        Matrix<float> getWeights();
        activation_t getActivation();

        void setWeights(Matrix<float> newWeights);
        void setActivation(activation_t act);
};


class ConvLayer : public Layer{
    
};


class MaxPoolLayer : public Layer{
    
};

#endif