layout: true
class: typo, typo-selection

---

count: false
class: nord-dark, middle, center

# The `projgeom` Package 🌌

@luk036 👨‍💻

2025-05-17 📅

---

## Introduction

**What is `projgeom`?** ✨🤔💡

*   A Python package for performing **geometric calculations** 📐🧮
*   Specifically designed for working with **projective geometry** and its related geometries like **Cayley-Klein** 🏛️, **Elliptic** 🔵, **Hyperbolic** 🔴, and **Perspective** geometry 🖼️
*   Provides tools for representing geometric objects like **points** ⚫ and **lines** ➖
*   Achieves its purpose through a series of **mathematical operations** ➗✖️ and **geometric algorithms** 🤖
*   Uses **abstract methods** 🧩 and **type hinting** ✍️ to define the structure of classes and their properties
*   Follows an **object-oriented programming** approach 🧱 to represent geometric entities and their relations

---

## Core Concepts

**Key Ideas** 🔑🧠💭

*   **Projective Geometry:** The fundamental space where objects like points and lines exist 🌌. The package provides a framework for this 🏗️
*   **Geometric Objects:** Points ⚫ and lines ➖ are the primary objects, often represented by coordinates
*   **Duality:** A core principle allowing interchangeability between points and lines 🔄. Many objects have a `dual()` method 🔀
*   **Perpendicularity (Polar/Pole):** The concept of perpendicularity is implemented, often via a `perp()` method, which returns the pole or polar of an object ⏹️
*   **Incidence:** Checking if a point lies on a line or vice versa ✔️. Represented by the `incident()` method 🔍
*   **Meet/Join:** Finding the intersection of two objects (meet) or the line connecting two points (join) ✖️. Represented by the `meet()` method 🤝

---

## Modules - Overview

**Package Structure** 📁🗂️📚

The package is organized into several modules, each focusing on specific geometries or object types:

*   `projgeom.ck_plane` - Cayley-Klein plane geometry operations ✨🏛️
*   `projgeom.ell_object` - Elliptic geometry objects 🔵🌍
*   `projgeom.hyp_object` - Hyperbolic geometry objects 🔴🌀
*   `projgeom.myck_object` - Custom Cayley-Klein points and lines 🌟🎨
*   `projgeom.persp_object` - Perspective geometry points and lines 🖼️👁️
*   `projgeom.pg_object` - Projective geometry objects (2D plane) 📐✏️
*   `projgeom.pg_plane` - Projective plane geometry functions (theorems, transformations) 🌐🔄
*   Euclidean geometry ???

---

## `projgeom.pg_plane` Module

**Projective Plane Functions** 🌐🧮

*   Defines a `ProjectivePlane` class and several functions related to projective geometry.
*   Provides a **framework** for working with points and lines in a projective plane. 🛠️
*   The `ProjectivePlane` is an abstract base class defining **basic operations** and **properties**.
*   Includes several **abstract methods** that need to be implemented by concrete subclasses.

---

**Key Functions (Theorems & Checks):** 📚🔍

*   `check_axiom()`: Verifies basic properties of projective geometry like **equality, collinearity, and commutativity**. ✅
*   `coincident()`: Checks if **three points are collinear** (lie on the same line). 📏
*   `check_pappus()`: Implements **Pappus's hexagon theorem**. ⬡
*   `tri_dual()`: Computes the **dual of a triangle** (the lines formed by its sides). 🔺
*   `persp()`: Checks if **two triangles are in perspective** (their corresponding sides intersect at collinear points). 👁️
*   `check_desargue()`: Implements **Desargues's theorem**. 🏛️
*   `harm_conj()`: Calculates the **harmonic conjugate of three collinear points**. 🎼
*   `involution()`: Performs an **involution transformation** on a point with respect to an origin and mirror line. 🔄

---

## `projgeom.ck_plane` Module

**Cayley-Klein Geometry** ✨🏛️🧩

*   Contains a set of classes and functions for working with **Cayley-Klein planes**
*   Provides tools for performing **calculations** 🧮 and **operations** ⚙️ in Cayley-Klein geometry
*   Main input objects are **Points** ⚫ and **Lines** ➖ in a Cayley-Klein plane, represented by `CayleyKleinPlanePointCk` and `LineCk` 📝
*   Outputs include various **geometric calculations** 📐 and **transformations** 🔄

---

**Key Functions:** 🛠️🔧⚒️

*   `perp()`: Finds **polar lines or poles of points** 🧲. Essential for various geometric constructions 🏗️
*   `altitude()`: Calculates the **altitude of a point with respect to a line** 📏
*   `is_perpendicular()`: Checks if **two lines are perpendicular** ⏹️✔️
*   `orthocenter()`: Determines the **orthocenter of a triangle** 🔺🎯
*   `reflect()`: Calculates the **reflection of a point across a mirror plane** 👥
*   `tri_altitude()`: Calculates a **list of altitudes of a triangle** 📐🔺

---

## Object Modules 📐🔵🔴🌟🖼️⚡

*   `projgeom.ell_object`: Defines `EllipticLine` and `EllipticPoint` classes. They have `dual()` and `perp()` methods. 🔄
*   `projgeom.hyp_object`: Defines `HyperbolicLine` and `HyperbolicPoint` classes. They also have `dual()` and `perp()` methods.
*   `projgeom.myck_object`: Defines `MyCkPoint` and `MyCkLine` classes, customized for Cayley-Klein geometry. Inherit from `PgObject`. Designed for working with coordinate data. Implement `dual()` and `perp()`.
*   `projgeom.persp_object`: Defines `PerspLine` and `PerspPoint` classes for perspective geometry. Have `dual()`, `midpoint()`, and `perp()`. Includes `is_parallel()` method. 🎨
*   `projgeom.pg_object`: Base module for objects in a 2D projective plane. Defines `PgObject`, `PgPoint`, and `PgLine`. Objects are represented by lists of three integers (coordinates). Includes core methods like `dual()`, `dot()` (checking if points lie on lines), `plckr()` (Plücker coordinates/cross product for line representation), `incident()`, `meet()`, and `parametrize()`. 🏗️

---

## Design Philosophy

**Under the Hood** 💡⚙️

*   **Abstract Methods & Type Hinting:** Used extensively to define clear interfaces and improve code readability and maintainability. 📝
*   **Object-Oriented Design:** Geometric objects are instances of classes with methods for operations. 🏗️
*   **Comprehensive Toolset:** Aims to be a powerful toolkit for creating and manipulating geometric objects easily. 🧰
*   **Mathematical Principles:** Built upon the consistent mathematical principles of projective spaces. ➗
*   **Logical Flow:** Basic operations like checking incidence or finding intersections are used to support higher-level geometric calculations and theorems. 🔄

---

## Examples

**Putting it to Use** 🧪🔧

*   Examples are provided within the documentation for many functions and methods.
*   Demonstrate importing objects and functions:
    ```python
    >>> from projgeom.hyp_object import HyperbolicLine, HyperbolicPoint
    >>> t = altitude(HyperbolicPoint(), HyperbolicLine())
    ```
    ```python
    >>> from projgeom.pg_object import PgPoint, PgLine
    >>> pt_p = PgObject()
    >>> ln_l = PgObject()
    >>> pt_p.incident(ln_l)
    False
    ```
*   Examples show how to create objects, perform operations like `incident()`, `dot()`, `cross()`, `check_desargue`, etc., and interpret the results.

---

## Conclusion

**Summary** ✅📝🎯

*   `proj_geom` is a comprehensive library 📚 for working with various geometries derived from projective geometry 🌌
*   It provides classes 🧱 for geometric objects and functions ⚙️ for performing operations and validating theorems 📜
*   The design is object-oriented 🖥️ and leverages abstract methods 🧩 and type hinting ✍️ for structure
*   Covers fundamental concepts like duality 🔄, perpendicularity ⏹️, incidence ✔️, meet/join ✖️🤝, and complex theorems 🧠

**GitHub** 🐙: [projgeom-py](https://github.com/luk036/projgeom-py) 🔗

---

class: nord-dark, middle, center

# Q&A 🎤
