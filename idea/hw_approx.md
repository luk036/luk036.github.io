# Hardware Approximation

            CPU/Instruction        FPGA/ASIC
--------------------------------------------------
data types  i32, i16, i8           16-bit, 24-bit
            f64, f32               Q0.12, Q0.24, UQ0.32
execution   serial                 serial/parallel

Adder
Multiplier
Counter             
FIFO
FSM

Table Look-up
Avoid sqrt(), e.g. use squared distance in K-mean algorithm

## Low discrepancy Sequence

reverse list

### van der Corput divmod

divmod(x, k),      x, k positive integer

k = 2, 4, 8, 16

k = 3, 7, (15), 5

### sin(), cos(), sqrt()

CORDIC = Table-lookup + FSM

## FIR filter Design

Butterworth filter

Convexity
taps

direct form, transposed form

Multiplierless

NNZ

