# Hardware Approximation

## Constant Multiplication

A simple temperature conversion case, but the same argument of AI/machine learning.

Temperature Conversion from c to f:

f = (9 * c) / 5 + 32
  = 1.8 * c + 32

Suppose it is used for displaying the home temperature on an air conditioner.
So the accuracy is up to the last digit.
The temperature range is from -9c to +30c.

1. Integer-Only Arithmetic (e.g embedded microcontroller)

#define K 117965   // round(9/5 * 2^16)
int c2f(int c) {
    return (int)(((int64_t)c * K + (1 << 15)) >> 16) + 32;
}

Suppose now the hardware is used for a more extreme environment.
So the accuracy is up to three decimal places. 
The temperature range is from -60c to +300c. 

The problem is not the accuracy, but how to **control** it.

Design is an art of trade-off

2. Approximate multiplier: remove certain gates from the circuits

   Controlled by Design Space Exploration (DSE):
   - Bayesian Optimization
   - Reinforcement Learning 

   Note: mean error is a wrong metric.
   It is easy to average out the worst cases.
   The correct metric should be the max error.
   
3. CSD Multiplier (multiplierless)

   Controllable by NNZ (Number of Non-Zero)
   
Prompt:

Write a demo program to illustrate how to use CSD multiplier technique to hardware approximate the temperature conversion from c to f (down to a Verilog output) based on the Python code in this project. Suppose it is used for displaying the home temperature on an air conditioner. So the accuracy is up to the last digit. The temperature range is from -9c to +30c. How many nnz (number of non-zero) is sufficient?

Suppose now the hardware is used for a more extreme environment. So the accuracy is up to three decimal places. The temperature range is from -60c to +300c. How many nnz (number of non-zero) is sufficient?

Low discrepancy Sequence
q
## divmod

divmod(x, k),      x, k positive integer

k = 2, 4, 8, 16

k = 3, 7, 15

## sin(), cos(), arctan()

CORDIC = Table-lookup + FSM

log(), exp()

inv()    Table-lookup + Newton-Raphson

## Cholesky Factorization -> LDLT

## QR factorization

## FIR filter
