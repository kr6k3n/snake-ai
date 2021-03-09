#include "training.h"


double gaussian()
{
    double r = rand1();
    return exp(-exp2((r-5E-1)/5E-2));
}


void mutate(neural_network* nn)
{
    for (size_t i = 0; i < (nn->shape_size-1); i++)
    {
        connection_layer *con = &nn->layer_connections[i];
        for (size_t j = 0; j < con->right_side; j++)
        {
            for (size_t k = 0; k < con->left_side; k++)
            {
                con->weights[j][k] = con->weights[j][k] * (1-gaussian());
            }
        }
        
    }
    
}