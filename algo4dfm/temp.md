
# Lecture 1b: DFM For Dummies

## @luk036

2023-09-06

] 

---

Faster, smaller & smarter
-------------------------

![iPhoneX](lec01.files/iPhoneX.jpg)

---

Silicon Gold Rush?
------------------

![SMIC](lec01.files/image008.jpg)

---

Current Transistor
----------------------------

-   High-K dielectrics, Metal Gate (HKMG)
-   "3D" gate

![FinFET](lec01.files/image009.png)

---

Lithography
-----------

.pull-left[

![Lithography](lec01.files/image011.jpg)

] .pull-right[

-   Photo-resist coating
-   Illumination
-   Exposure
-   Etching
-   Impurities Doping
-   Metal connection

]

---

Process-Design Gap
------------------

![Process-Design Gap](lec01.files/image013.jpg)

---

Problem Visualization
---------------------

![ibm](lec01.files/image015.png)

---

Chemical Mechanical Polishing
-----------------------------

![CMP](lec01.files/image017.jpg)

---

ECP & CMP
---------

.pull-left70[

![ECP](lec01.files/image021.jpg)

] .pull-right30[

![CMP](lec01.files/image019.jpg)

]

---

count: false
class: nord-light, middle, center

Process Variation
=================

---

Total Thickness Variation Per Node
----------------------------------

![Thickness Variation](lec01.files/image023.jpg)

---

"Slippery Fish" at 45nm
-----------------------

-   Process variation, impacting yield and performance
-   More restricted design rules (RDRs)
    -   +3 or more rules at 45nm
    -   +100 or more rules at 32nm
    -   +250 or more rules at 22nm
-   More rules implies larger die size, lower performance
-   10nm is not sci-fiction due to FinFET technology

---

count: false
class: nord-light, middle, center

DFM
===

---

What is DFM?
------------

-   Design for money?
-   Design for Manufacturing
-   Design for Manufacturability
    - Refer to a group of challenges less than 130nm 
    - The engineering practice of designing integrated circuits (ICs) to optimize their manufacturing ease and production cost given performance, power and reliability requirements
    - A set of techniques to modify the design of ICs to improve their functional yield, parametric yield or their reliability

---

## Why is it important?

- Achieving high-yielding designs in the state-of-the-art VLSI technology is extremely challenging due to the miniaturization and complexity of leading-edge products
- The manufacturing process becomes more sensitive to variations and defects, which can degrade the quality and functionality of the chips
- DFM can help to address various manufacturing issues, such as lithography hotspots, CMP dishing and erosion, antenna effects, electromigration, stress effects, layout-dependent effects and more

---

## How is it applied?

- DFM can be applied to various aspects of IC design, such as circuit design, logic design, layout design, verification and testing
- Each aspect has its own specific DFM guidelines and best practices that designers should follow to ensure manufacturability
- For example, some general DFM guidelines for layout design are:
  - Use regular and uniform layout structures
  - Avoid narrow or long metal wires
  - Avoid acute angles or jogs in wires
  - Avoid isolated or floating features
  - Use dummy fill to improve planarity and density uniformity
  - Use recommended design rules and constraints from foundries

---

## What are the benefits?

- By applying DFM techniques in the physical design stage of IC development, designers can:
  - Reduce the number of design iterations
  - Improve the collaboration with foundries
  - Enhance the product performance and functionality
  - Achieve faster time to market and lower production costs

---

DFM Market Share 2008
---------------------

![Market Share](lec01.files/image025.png)

---

DFM Forecast 2009 in $M
------------------------

![forecast](lec01.files/image027.png)

---

Increasing Importance of DFM
----------------------------

![trend](lec01.files/image029.jpg)

---

DFM Analysis and Verification
-----------------------------

-   Critical area analysis
-   CMP modeling
-   Statistical timing analysis
-   Pattern matching
-   Lithography simulation
-   Lithographic hotspot verification

---

2D Pattern Matching in DRC+
---------------------------

![DRC+](lec01.files/image031.jpg)

---

Contour Based Extraction
------------------------

![contour](lec01.files/image033.jpg)

---

DFM Enhancement and Optimization
--------------------------------

-   Wire spreading
-   Dummy Filling
-   Redundant Via Insertion
-   Optical proximity correlation (OPC)
-   Phase Shift Masking (PSM)
-   Double/Triple/Multiple Patterning
-   Statistical timing and power optimization

---

Dummy Filling
-------------

![filling](lec01.files/image035.jpg)

---

"Smart" Filling
---------------

!["Smart" Filling](lec01.files/image036.png)

---

Redundant Via Insertion
-----------------------

-   Also known as double via insertion.
-   Post-routing RVI (many EDA tools already have this feature)
-   Considering RVI during routing

![RVI](lec01.files/image038.jpg)

Looks good, right?

But actually only few people are using this!

Why?

---

Multiple Patterning (MPL)
-------------------------

-   Instead of exposing the photoresist layer once under one mask, MPL
    exposes it twice by splitting the mask into "k" parts, each with
    features less dense.

![MPL](lec01.files/image040.jpg)

---

## What are the challenges of DFM?

- DFM is not a fixed set of rules, but rather a flexible and evolving methodology that depends on the product requirements, the manufacturing technology and the industry standards
- DFM can also be combined with other design methodologies, such as DFT, DFR, DFLP and DFS, to create a holistic approach to product development
- DFM requires strong capabilities in research, supply chain, talent, IP protection and government policies

---

Course Structure
----------------

.pull-left[

-   Describe the DFM problems that arise from.
-   Abstract the problems in mathematical forms
-   Describe the algorithms that solve the problems
-   Discuss the alternative algorithms and possible improvement.
-   Discuss if the algorithms can be applied to other area.
-   Only describe the key idea in lectures. Details are left for paper
    reading if necessary.

---

Not covered
-----------

-   Algorithms for 3D problems
-   Packaging
-   Machine Learning/AI Based algorithm

