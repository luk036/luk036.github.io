# Markdown Slides using Remarkjs

👨🏻‍🏫 @luk036

---

### Why Markup Language?

- Separate "content" .small[with] "style".
- Use CSS file to configure style.
- Use Javascript to render mathematical equations.

### Why Markdown?

- For simple writing

---

### Render Mathematical Equations using MathJax

- Point: projection of $p=[x,y,z]$ to $z=1$:

  $$\{x', y'\} = (\frac{x}{z}, \frac{y}{z})$$

- $[\alpha x, \alpha y, \alpha z]$ for
  all $\alpha \neq 0$ are representing
  the same point.

- For instance, $[1, 5, 6]$ and
  $[-10, -50, -60]$ are representing the
  same point $(1/6, 5/6)$

- $p_\infty = [x, y, 0]$ is a point
  at _infinity_.

---

### Render Diagram using Mermaid

.mermaid[

<pre>
  sequenceDiagram
  participant Alice
  participant Bob
  Alice->>John: Hello John, how are you?
  loop Healthcheck
      John->>John: Fight against hypochondria
  end
  Note right of John: Rational thoughts <br/>prevail...
  John-->>Alice: Great!
  John->>Bob: How about you?
  Bob-->>John: Jolly good!
</pre>

]

---

### Table

| Costs        | 28nm      | 20nm        |
| ------------ | --------- | ----------- |
| Fab Costs    | 3B        | 4B - 7B     |
| Process R&D  | 1.2B      | 2.1B - 3B   |
| Mask Costs   | 2M - 3M   | 5M - 8M     |
| Design Costs | 50M - 90M | 120M - 500M |
