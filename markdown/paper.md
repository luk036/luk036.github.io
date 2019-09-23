title: Markdown Slides using Remarkjs
class: animation-fade
layout: true

.bottom-bar[ {{title}} ]

---
class: impact
# {{title}}
## Wai-Shing Luk

---

### Why Markup Language?

-   Separate "content" with "style".
-   Use CSS file to configure style.
-   Use Javascript to render mathematical equations.

### Why Markdown?

-   For simple writing

---
### A simple example `intro.md`

.small[

```markdown
title: Markdown Slide
class: animation-fade
layout: true

.bottom-bar[ {{title}} ]

---
class: impact
# {{title}}
## Wai-Shing Luk

---
### Why Markup Language?

-   Separate "content" with "style".
-   Use CSS file to configure style.
-   Use Javascript to render mathematical equations.
...
```
]

---

### A simple HTML wrapper `intro.html`

.small[

```html
<!DOCTYPE html>
<html><head>
  <meta charset="UTF-8">
  <title>Markdown Introduction</title>
  <link rel="stylesheet" href="../style.css">
  <script src="../remark.min.js"></script>  
  <script>
    function create() {
      var options = {
*       sourceUrl: 'intro.md', // the file you really need to write 
        ratio: '16:9', // or '4:3'
        highlightLines: true,
        countIncrementalSlides: false,
        highlightStyle: 'googlecode' 
      };
      return remark.create(options);
    }
  </script></head>
<body onload="slideshow = create()"></body>
</html>
```

]

---

### Render Mathematical Equations using KaTeX

.small[

```html
  <link rel="stylesheet" type="text/css" href="../katex/katex.min.css"/>
  <script src="../katex/katex.min.js" type="text/javascript"></script>
  <script src="../katex/contrib/auto-render.min.js"
    type="text/javascript"></script>
  <script>
    function create() {
      var options = { /* ... */ };
      var renderMath = function() {
        renderMathInElement(document.body, {delimiters: [
            {left: "$$", right: "$$", display: true},
            {left: "$", right: "$", display: false},
            {left: "\\[", right: "\\]", display: false},
            {left: "\\(", right: "\\)", display: false},
        ]});
      }
      return remark.create(options, renderMath);
    }
  </script>  
```
]

---

### A simple example

.small[
.col-6[

```markdown
-   Point: projection of $p = [x, y, z]$ 
    to $z = 1$:
  
  $$(x', y') = ({x \over z}, {y \over z})$$

-   $[\alpha x, \alpha y, \alpha z]$ for 
    all $\alpha \neq 0$ are representing 
    the same point.

-   For instance, $[1, 5, 6]$ and 
    $[-10, -50, -60]$ are representing the 
    same point $(1/6, 5/6)$

-   $p_\infty = [x, y, 0]$ is a point 
    at *infinity*.
```

]
.col-6[
-   Point: projection of $p = [x, y, z]$ 
    to $z = 1$:
  
  $$(x', y') = ({x \over z}, {y \over z})$$

-   $[\alpha x, \alpha y, \alpha z]$ for 
    all $\alpha \neq 0$ are representing 
    the same point.

-   For instance, $[1, 5, 6]$ and 
    $[-10, -50, -60]$ are representing the 
    same point $(1/6, 5/6)$

-   $p_\infty = [x, y, 0]$ is a point 
    at *infinity*.
]
]

---

### How to make a two-column slide

```markdown
.col-6[

Left-hand side

]
.col-6[

Right-hand side

]
```

---

### Render Diagram using Mermaid

.small[

```html
  <script src="../mermaid/mermaid.min.js"></script>
  <link rel="stylesheet" href="../mermaid/mermaid.css"/>
  <script>
    function create() {
      var options = { /* ... */};
      mermaid.initialize({
        startOnLoad: false,
        cloneCssStyles: false });
      var render = function() {
        var diagrams = document.querySelectorAll('.mermaid');
        var i;
        for(i=0;i<diagrams.length;i++){
          if(diagrams[i].offsetWidth>0){
            mermaid.init(undefined, diagrams[i]); } } }
      return remark.create(options, render); }
  </script>
```
]

---

### A simple example

.col-6[

```html
<div class="mermaid">
graph LR
  A-->B
  B-->C
  C-->A
  D-->C
</div>
```

]
.col-6[

<div class="mermaid">
graph LR
  A-->B
  B-->C
  C-->A
  D-->C

/* Reload the page if you see this message */
</div>

]


---

class: impact

Q & A 🗣️
==========
