
class: middle, center

# Ellipsoid method Revisited

Wai-Shing Luk

2018-11-01

---

## Basic Ellipsoid Method

-   An ellipsoid $\mathcal{E}(x_c, P)$ is specified as a set
    $$\\{x \mid (x-x_c)P^{-1}(x-x_c) \leq 1 \\},$$ where $x_c$ is the center of the ellipsoid, $P$ is a symmetric positive matrix (SPD).

![](ellipsoid.files/ellipsoid.svg)

---

## Python code

```python
import numpy as np

class ell:
    def __init__(self, val, x):
        '''ell = { x | (x - xc)' * P^-1 * (x - xc) <= 1 }'''
        self._n = n = len(x)
        self.c1 = float(n*n) / (n*n-1)
        self._xc = x.copy()
        if np.isscalar(val):
            self.P = val * np.identity(n)
        else:
            self.P = np.diag(val)

    def update_core(self, calc_ell, cut): ...
    def calc_cc(self, ...): ...
    def calc_dc(self, ...): ...
    def calc_ll(self, ...): ...
```

---

## Updating the ellipsoid (deep-cut)

-   Calculation of minimum volume ellipsoid covering:
    $$\mathcal{E} \cap \\{z \mid g^\top (z - x_c) + h \leq 0\\}$$
-   Let $\tilde{g} = P\,g$, ${\color{red}\tau} = \sqrt{g^\top\tilde g}$,
    ${\color{red}\alpha} = h/{\color{red}\tau}$.
-   If $\alpha > 1$, intersection is empty.
-   If $\alpha < -1/n$ (shallow cut), no smaller ellipsoid can be found.
-   Otherwise, 
      $$\begin{array}{lll}
     x_c^+ &=& x_c - {1+n{\color{red}\alpha} \over (n+1) \color{red}\tau} \tilde{g}  \\\\
     P^+ &=& \frac{n^2(1-{\color{red}\alpha}^2)}{n^2 - 1}\left(P - \frac{2\rho}{(1+{\color{red}\alpha})\tau^2} \tilde{g}\tilde{g}^\top\right)
      \end{array}$$

---

## Updating the ellipsoid (deep-cut)

-   Calculation of minimum volume ellipsoid covering:
    $$\mathcal{E} \cap \\{z \mid g^\top (z - x_c) + h \leq 0 \\}$$
-   Let $\tilde{g} = P\,g$, $\tau^2 = g^\top P g$.
-   If $n \cdot h < -\tau$ (shallow cut), no smaller ellipsoid can be found.
-   If $h > \tau$, intersection is empty.
-   Otherwise,
 $$x_c^+ = x_c - \frac{\rho}{ \tau^2 } \tilde{g}, \qquad
    P^+ = {\color{orange}\delta\cdot}\left(P - \frac{\sigma}{ \tau^2 } \tilde{g}\tilde{g}^\top\right)
 $$ where

 $$\rho = \frac{ {\color{red}\tau}+nh}{n+1}, \qquad
  \sigma = \frac{2\rho}{ {\color{red}\tau}+h}, \qquad
  \delta = \frac{n^2(\tau^2 - h^2)}{(n^2 - 1)\tau^2} $$

---

## Updating the ellipsoid (cont'd)

-   Even better, split $P$ into two variables $\kappa \cdot Q$
-   Let $\tilde{g} = Q \cdot g$, $\omega = g^\top Q g$, $\tau^2 = {\kappa\cdot}  \omega$,
 $$x_c^+ = x_c - \frac{\rho}{\omega} \tilde{g}, \qquad
    Q^+ = Q - \frac{\sigma}{\omega} \tilde{g}\tilde{g}^\top, \qquad
    \kappa^+ =  {\delta\cdot} \kappa
 $$
-   Reduce $n^2$ multiplications per iteration.

---

## Python code (updating)

```python
def update_core(self, calc_ell, cut):
    g, beta = cut
    Qg = self.Q.dot(g)
    omega = g.dot(Qg)
    tsq = self.kappa * omega
    status, params = calc_ell(beta, tsq)
    if status != 0:
        return status, tsq
    rho, sigma, delta = params
    self._xc -= (rho / omega) * Qg
    self.Q -= (sigma / omega) * np.outer(Qg, Qg)
    self.kappa *= delta
    return status, tsq
```


---

## Python code (deep cut)

```python
def calc_dc(self, beta, tsq):
    '''deep cut'''
    if beta == 0.:
        return 0, self.calc_cc(tsq)
    t = tsq - beta*beta
    if t < 0.:
        return 1, None    # no sol'n
    n = self._n
    tau = math.sqrt(tsq)
    gamma = tau + n * beta
    if gamma < 0.:
        return 3, None  # no effect
    rho = gamma / (n + 1)
    sigma = 2. * rho / (tau + beta)
    delta = self.c1 * t / tsq
    params = (rho, sigma, delta)
    return 0, params
```

---

## Parallel Cuts

-   Oracle returns a pair of cuts instead of just one.

-   The pair of cuts is given by $g$ and $(\beta_1, \beta_2)$ such that:
    $$\begin{array}{l}
    g^\top (x - x_c) + \beta_1 \leq 0,  \\\\
    g^\top (x - x_c) + \beta_2 \geq 0,
    \end{array}$$ for all $x \in \mathcal{K}$.

-   Only linear inequality constraint can produce such parallel cut:
    $$ l \leq a^\top x + b \leq u, \qquad L \preceq F(x) \preceq U $$

-   Usually provide faster convergence.


---

## Parallel Cuts

![img](ellipsoid.files/parallel_cut.svg)

---

## Updating the ellipsoid

-   Let $\tilde{g} = Q \cdot g$, $\omega = g^\top Q g$, $\tau^2 = \kappa \omega$.
-   Let $l = \beta_2 - \beta_1$. If $l < 0$, intersection is empty.
-   Let $p = \beta_1 \beta_2$. If $p < -\tau^2/n$, no smaller ellipsoid can be found. 
-   Let $t_2 = \tau^2 - \beta_2^2$. If $t_2 < 0$, it reduces to deep-cut with $h = \beta_1$.
-   Otherwise, Let $t_1 = \tau^2 - \beta_1^2$, $m = (\beta_1 + \beta_2)/2$. Update $x_c$, $Q$, and $\kappa$ using:

 $$\begin{array}{lll}
      \xi &=& \sqrt{t_1 t_2 + (n \cdot m \cdot l)^2}, \\\\
      \sigma &=& (n + (\tau^2 - p - \xi)/(2 m^2)) / (n + 1) \\\\
      \rho &=& \sigma \cdot m, \\\\
      \delta &=& \frac{n^2}{n^2-1} ((t_1 + t_2)/2 + \xi/n)/\tau^2
 \end{array}$$


---

## Python code (parallel cut)


```python
def calc_ll_core(self, b0, b1, tsq):
    t1 = tsq - b1*b1
    if t1 < 0. or not self.use_parallel:
        return self.calc_dc(b0, tsq)

    l = b1 - b0
    if l < 0:
        return 1, None  # no sol'n

    n = self._n
    p = b0*b1
    if n*p < -tsq:
        return 3, None  # no effect

    t0 = tsq - b0*b0
    b = (b0 + b1)/2
    xi = math.sqrt(t0*t1 + (n*b*l)**2)
    sigma = (n + (tsq - p - xi)/(2*b*b)) / (n + 1)
    rho = sigma * b
    delta = self.c1 * ((t0 + t1)/2 + xi/n) / tsq
    return 0, (rho, sigma, delta)
```

---

## Example: FIR filter design

![img](ellipsoid.files/fir_strctr.svg)

-   The time response is: 
    $$y[t] = \sum_{k=0}^{n-1}{h[k]u[t-k]}$$


---

## Example: FIR filter design (cont'd)

-   The frequency response:
    $$H(\omega)~=~\sum_{m=0}^{n-1} h(m)e^{-jm\omega}$$ 

-   The magnitude constraints on frequency domain are expressed as

    $$L(\omega)~\leq~|H(\omega)|~\leq~U(\omega),~\forall~\omega\in(-\infty,+\infty)$$

    where $L(\omega)$ and $U(\omega)$ are the lower and
    upper (nonnegative) bounds at frequency $\omega$ respectively.

-   The constraint is non-convex in general.


---

## Example: FIR filter design (cont'd)

-   However, via *spectral factorization*, it can transform into a convex one:
    $$L^2(\omega)~\leq~R(\omega)~\leq~U^2(\omega),~\forall~\omega\in(0,\pi)$$
    where
    -   $R(\omega)=\sum_{i=-1+n}^{n-1} r(t)e^{-j{\omega}t} = |H(\omega)|^2$
    -   $\mathbf{r}=(r(-n+1),r(-n+2),...,r(n-1))$ are the
        autocorrelation coefficients.


---

## Example: FIR filter design (cont'd)

-   $\mathbf{r}$ can be determined by $\mathbf{h}$:

    $$r(t)~=~\sum_{i=-n+1}^{n-1}{h(i)h(i+t)},~t\in\mathbf{Z}.$$ 

    where $h(t)=0$ for $t < 0$ or $t > n-1$.

-   The whole problem can be formulated as: 

$$\begin{array}{ll}
  \text{min}  & \gamma \\\\
  \text{s.t.} & L^2(\omega) \leq R(\omega) \leq U^2(\omega), \; \forall \omega \in [0,\pi]   \\\\
              & R(\omega) > 0, \forall \omega \in [0,\pi]
\end{array}$$


---

## Experiment

![Result](ellipsoid.files/lowpass.svg)

---

## Example: Maximum Likelihood estimation

 $$\begin{array}{ll}
      \min_{\kappa, p}   &      \log \det (\Omega(p) + \kappa I) + \mathrm{Tr}((\Omega(p) + \kappa I)^{-1}Y) \\\\
      \text{s.t.} & \Omega(p) {\color{red}\succeq} 0, \kappa {\color{red}\geq} 0 \\\\
 \end{array}$$

Note: 1st term is concave, 2nd term is convex

-   However, if there is enough samples such that $Y$ is a positive
    definite matrix, then the function is convex within $[0, 2Y]$


---

## Example: Maximum Likelihood estimation (cont'd)

-   Therefore, the following problem is convex:

$$\begin{array}{ll}
      \min_{\kappa, p}   &   \log \det V(p) + \mathrm{Tr}(V(p)^{-1}Y) \\\\
      \text{s.t.} & \Omega(p) + \kappa I = V(p) \\\\
                    & 0 \preceq V(p) \preceq 2Y, \kappa {>} 0
\end{array}$$

---

class: middle, center

Discrete Optimization
=====================

---

## Why Discrete Convex Programming

-   Many engineering problems can be formulated as a convex/geometric
    programming, e.g. digital circuit sizing

-   Yet in an ASIC design, often there is only a limited set of choices
    from the cell library. In other words, some design variables
    are discrete.

-   The discrete version can be formulated as a Mixed-Integer Convex
    programming (MICP) by mapping the design variables to integers.


---

## What's Wrong w/ Existing Methods?

-   Mostly based on relaxation.

-   Then use the relaxed solution as a lower bound and use the
    branch–and–bound method for the discrete optimal solution.

    -   Note: the branch-and-bound method does not utilize the convexity
        of the problem.
-   What if I can only evaluate constraints on discrete data?
    Workaround: convex fitting?


---

## Mixed-Integer Convex Programming

Consider: 
$$\begin{array}{ll}
        \text{minimize}      & f_0(x), \\\\
        \text{subject to}    & f_j(x) \leq 0, \; \forall j=1,2,\ldots \\\\
                             & x \in \mathbb{D} 
\end{array}$$ 
where 
-  $f_0(x)$ and $f_j(x)$ are "convex"
-  Some design variables are discrete.


---

## Oracle Requirement

-   The oracle looks for the nearby discrete solution $x_d$ of $x_c$
    with the cutting-plane:
    $$g^\top (x - x_d) + h \leq 0, h \geq 0, g \neq 0$$

-   Note: the cut may be a shallow cut.
-   Suggestion: use different cuts as possible for each iteration (e.g.
    round-robin the evaluation of constraints)


---

## Example: FIR filter design

![img](ellipsoid.files/lowpass_ripple.svg)

---

class: center, middle

Questions?
==========

