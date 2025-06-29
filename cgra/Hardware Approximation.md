# Hardware Approximation

## Temperature Conversion

Performing temperature conversion (e.g., Celsius to Fahrenheit or vice versa) without using division in embedded systems can be useful when division operations are expensive or unsupported. Here are some efficient approaches:

---

### 1. **Use Fixed-Point Arithmetic with Pre-Scaling**

Since division is costly, pre-multiply by the reciprocal (using fixed-point arithmetic) and then shift.

   **Example: Celsius to Fahrenheit without Division**
   - Formula: \( F = (C \times 9/5) + 32 \)
   - Instead of dividing by 5, multiply by a pre-scaled inverse:
     ```c
     int16_t celsius_to_fahrenheit(int16_t c) {
         // Approximate (9/5) as (9 * 1/5) using fixed-point (1/5 ≈ 0.200)
         // Multiply by 205 (≈ 1/5 * 1024) then shift right by 10 (≈ /1024)
         int32_t temp = c * 9;
         temp = (temp * 205) >> 10;  // Equivalent to (temp * 9 / 5)
         return temp + 32;
     }
     ```
   - **Trade-off:** Introduces small error due to fixed-point approximation.

---

### 2. **Use Lookup Tables (LUT)**
   If the input range is small and known (e.g., -40°C to 125°C for many sensors), precompute conversions in a lookup table:
   ```c
   const int16_t celsius_to_fahrenheit_lut[256] = { -40, ..., 257 };  // Precomputed values
   int16_t celsius_to_fahrenheit(int8_t c) {
       return celsius_to_fahrenheit_lut[c + 40];  // Offset by -40°C
   }
   ```
   - **Pros:** Extremely fast, no division.
   - **Cons:** Memory usage scales with range.

---

### 3. **Multiply and Shift (Power-of-Two Approximation)**
   Approximate division by a power of two using right shifts:
   - Example: \( F = (C \times 1.8) + 32 \)
   - Approximate \( 1.8 \approx 1 + 0.8 \), where \( 0.8 \approx 819/1024 \):
     ```c
     int16_t celsius_to_fahrenheit(int16_t c) {
         int32_t temp = c;
         temp = temp + ((temp * 819) >> 10);  // ≈ temp * 1.8
         return temp + 32;
     }
     ```
---

### **Best Approach?**
- **For small ranges:** Use a **LUT** (fastest, no error).
- **For general cases:** **Fixed-point pre-scaling** (balance of speed and accuracy).
- **For systems with multipliers:** **Newton-Raphson approximation**.

Would you like an optimized implementation for a specific microcontroller (e.g., ARM Cortex-M, AVR)?

---

## Gaussian Blur

### 5×5 Gaussian Blur Kernel

A **Gaussian Blur 5×5 kernel** is a weighted matrix used in image processing to blur an image by averaging pixel values with weights based on the Gaussian (normal) distribution. Here's a standard **5×5 Gaussian kernel** with **σ = 1.0** (standard deviation):

$$
\frac{1}{273}
\begin{bmatrix}
1 & 4 & 7 & 4 & 1 \\
4 & 16 & 26 & 16 & 4 \\
7 & 26 & 41 & 26 & 7 \\
4 & 16 & 26 & 16 & 4 \\
1 & 4 & 7 & 4 & 1 \\
\end{bmatrix}
$$

---

### Explanation:
- The weights are derived from the **2D Gaussian function** \( G(x, y) = \frac{1}{2\pi \sigma^2} e^{-\frac{x^2 + y^2}{2\sigma^2}} \).
- The kernel is **normalized** (sum of all weights = 1), so we divide by **273** (the sum of the matrix values).
- This kernel provides a **smooth blur** while preserving edges better than a uniform box blur.

---

### Alternative (Simpler Approximation):
A commonly used approximation (less computationally expensive) is:

$$
\frac{1}{256}
\begin{bmatrix}
1 & 4 & 6 & 4 & 1 \\
4 & 16 & 24 & 16 & 4 \\
6 & 24 & 36 & 24 & 6 \\
4 & 16 & 24 & 16 & 4 \\
1 & 4 & 6 & 4 & 1 \\
\end{bmatrix}
$$

Here, the sum of the weights is **256**, making normalization efficient for computers (bit-shifting).

### Usage:
When applying this kernel, **convolve** it with the image (each pixel is replaced by a weighted average of its 5×5 neighborhood).

Would you like the kernel for a different σ value?

