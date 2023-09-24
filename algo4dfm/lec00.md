layout: true
class: typo, typo-selection

---

class: nord-dark, middle, center

Lecture 1a: 可制造性设计算法
============================

.pull-left[

@luk036
-------

2023-09-06

] .pull-right[

![image](figs/dfm.svg)

]

---

课程概要
--------

-   任课教师: 陆伟成, 📪 联系方式: <luk@fudan.edu.cn>, 📍 办公地址:
    微电子楼 383 室. 📆 办公时间 F6-F8 或预约
-   Lecture: 📆 W8-W10, 📍Z2212
-   Lecture notes will be available at
    <https://luk036.github.io/algo4dfm/>

---

👓 教学目的
----------

-   了解超大规模集成电路可制造性设计的发展
-   掌握可制造性设计自动化的一些实用算法及其基本原理
-   *宁缺勿滥* -- avoid "no-time-to-think" syndrome

---

教学内容
--------

-   简介：可制造性设计的发展概况，工艺参数变动对芯片性能影响的问题
-   基本软件开发原理，电子设计自动化，
-   基本算法原理：算法范式、算法复杂度，优化算法简介
-   统计与空间相关性提取：参数与非参数方法
-   鲁棒性电路优化算法，仿射算术、鲁棒几何规划问题。
-   基于统计时序分析的时钟偏差安排
-   交替相移掩模简介，版图相位分配问题，Hadlock 算法
-   光刻问题，双/多图案技术，
-   混合光刻技术
-   Redundant Via Insertion

---

📚 Reference books
-----------------

-   Michael Orshansky, Sani R. Nassif, and Duane Boning (2008) [Design
    for Manufacturability and Statistical Design: A Constructive
    Approach](https://rd.springer.com/book/10.1007/978-0-387-69011-7)
-   Artur Balasinski (2014) [Design for
    Manufacturability](https://rd.springer.com/book/10.1007/978-1-4614-1761-3)
-   Bei Yu and David Z. Pan (2016) [Design for Manufacturability with
    Advanced
    Lithography](https://rd.springer.com/book/10.1007/978-3-319-20385-0)
-   G. Ausiello et al. Complexity and Approximation: Combinatorial
    Optimization Problems and Their Approximability Properties,
    Springer-Verlag, 1999.
-   N. Sherwani, Algorithms for VLSI Physical Design Automation (3rd
    version), KAP, 2004.

---

课程考核及成绩评定
------------------

| 考核指标  | 权重 | 评定标准           |
| --------- | ---- | ------------------ |
| 出勤      | 10%  | 平时上课的参与度   |
| 课堂表现  | 10%  | 上课提问和问题回答 |
| 作业/实验 | 40%  | PPT 讲演           |
| 课程论文  | 40%  | 论文阅读报告       |

---

任课教师简介
------------

-   Working on "DfM" for over 10 years.
-   Working on large-scale software development for almost 20 years.
-   Working on algorithm design for over 20 years.

---

📜 My Publications (DfM related) I
------------------------------------

-   Ye Zhang, Wai-Shing Luk et al. Network flow based cut redistribution
    and insertion for advanced 1D layout design, Proceedings of 2017
    Asia and South Pacific Design Automation Conference (ASP-DAC),
    (**awarded best paper nomination**)
-   Yunfeng Yang, Wai-Shing Luk et al. Layout Decomposition
    Co-optimization for Hybrid E-beam and Multiple Patterning
    Lithography, in Proceeding of the 20th Asia and South Pacific Design
    Automation Conference (2015)
-   Xingbao Zhou, Wai-Shing Luk, et. al. "Multi-Parameter Clock Skew
    Scheduling." Integration, the VLSI Journal (accepted).
-   Ye Zhang, Wai-Shing Luk et al. Layout Decomposition with Pairwise
    Coloring for Multiple Patterning Lithography, Proceedings of 2013
    International Conference on Computer Aided-Design (**awarded best
    paper nomination**)
-   魏晗一，陆伟成，一种用于双成像光刻中的版图分解算法，《复旦学报(自然科学版)》，2013

---

📜 My Publications (DfM related) II
-------------------------------------

-   Yanling Zhi, Wai-Shing Luk, Yi Wang, Changhao Yan, Xuan Zeng,
    Yield-Driven Clock Skew Scheduling for Arbitrary Distributions of
    Critical Path Delays, IEICE TRANSACTIONS on Fundamentals of
    Electronics, Communications and Computer Sciences, Vol. E95-A,
    No.12, pp.2172-2181, 2012.
-   李佳宁，陆伟成，片内偏差空间相关性的非参数化估计方法，《复旦学报(自然科学版)》
    Non-parametric Approach for Spatial Correlation Estimation of
    Intra-die Variation, 2012，vol. 51, no 1, pp. 27-32
-   Wai-Shing Luk and Huiping Huang, Fast and Lossless Graph Division
    Method for Layout Decomposition Using SPQR-Tree, Proceedings of 2010
    International Conference on Computer Aided-Design, pp. 112-115, 2010

---

📜 My Publications (DfM related) III
--------------------------------------

-   Qiang Fu, Wai-Shing Luk et al., Intra-die Spatial Correlation
    Extraction with Maximum Likelihood Estimation Method for Multiple
    Test Chips, IEICE TRANSACTIONS on Fundamentals of Electronics,
    Communications and Computer Sciences,
    Vol.E92-A,No.12,pp.-,Dec. 2009.
-   Qiang Fu, Wai-Shing Luk et al., Characterizing Intra-Die Spatial
    Correlation Using Spectral Density Fitting Method, IEICE
    TRANSACTIONS on Fundamentals of Electronics, Communications and
    Computer Sciences, Vol. 92-A(7): 1652-1659, 2009.
-   Yi Wang, Wai-Shing Luk, et al., Timing Yield Driven Clock Skew
    Scheduling Considering non-Gaussian Distributions of Critical Path
    Delays, Proceedings of the 45th Design Automation Conference, USA,
    pp. 223-226, 2008.
-   宋宇, 刘学欣, 陆伟成, 唐璞山, 一种鲁棒性几何规划新方法设计两级运放,
    微电子学与计算机, 2008 年 25 卷 3 期, 175-181 页.

---

📜 My Publications (DfM related) IV
-------------------------------------

-   方君, 陆伟成, 赵文庆.
    工艺参数变化下的基于统计时序分析的时钟偏差安排,
    计算机辅助设计与图形学报，第 19 卷，第 9 期，pp.1172\~1177，2007 年
    9 月
-   FANG Jun, LUK Wai-Shing et al., True Worst-Case Clock Skew
    Estimation under Process Variations Using Affine Arithmetic, Chinese
    Journal of Electronics, vol. 16, no. 4, pages 631-636, 2007.
-   Xuexin Liu, Wai-Shing Luk et al., Robust Analog Circuit Sizing Using
    Ellipsoid Method and Affine Arithmetic, in Proceeding of the 12th
    Asia and South Pacific Design Automation Conference, pages
    203-208, 2007.
-   J. Fang, W.-S. Luk and W. Zhao. A Novel Statistical Clock Skew
    Estimation Method, in The Proceedings of 8th International
    Conference on Solid-state and Integrated Circuit Technology,
    pp.1928-1930, 2006.

---

class: nord-dark, middle, center

.pull-left[

Q & A 🙋️
========

] .pull-right[

![image](figs/questions-and-answers.svg)

]
