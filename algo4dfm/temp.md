\[redundant via insertion for DPL\][Given the minimum distance and a layout whose via layers are manufacturable with DPL. On the target via layer, perform redundant via insertion for DPL such that the redundant via insertion rate is the objective to be maximized, while the target via layer is still manufacturable with DPL.]{}

The sets of original and redundant vias are written as $V_O$ and $V_R$ respectively, and $V_A=V_O\cup V_R$. We construct two undirected graphs: matching graph ($G_m=(V_m, E_m)$) and conflict graph ($G_c=(V_c, E_c)$). The $i$-th via $v_i$ in $V_A$ is represented with $v_i^m\in V_m$ and $v_i^c\in V_c$ respectively. From now on, we will use $v_i$, $v_i^m$ and $v_i^c$ indistinguishably to indicate the $i$-th via in $V_A$. Thus we can write $V_m=V_c=V_A$.

The construction of $E_m$ and $E_c$ are introduced as follows. For each $v_i^m\in V_O$, without losing generality we assume its redundant via candidates are $ \{v_j^m, v_k^m \} $. Then we construct two edges to connect $(v_i^m, v_j^m)$ and $(v_i^m, v_k^m)$ respectively, indicating that $v_j^m$ and $v_k^m$ can be assigned to $v_i^m$ to improve its reliability. Therefore, on $G_m$, we should maximize the number of original vias that are assigned redundant vias to maximize the overall yield. Moreover, it is obvious that $G_m$ is a bipartite graph. Consequently, we can formulate a maximum bipartite matching problem on $G_m$.

A maximum bipartite matching problem can be transformed to a maximum flow problem. The transformation can be conducted as follows. Firstly, make $G_m=(V_m, E_m)$ a directed graph by pointing each edge from an original via to a redundant via. Then add two nodes $V_m=V_m\cup \{s,t\} $. Afterwards, construct an edge $(s, v_i^m)$ for each $v_i^m\in V_O$, and an edge $(v_i^m, t)$ for each $v_i^m\in V_R$. For each edge $(v_i^m, v_j^m)\in E_m$, we set its capacity as $c_{i,j}=1$ and its flow is written as $f_{i,j}$. Therefore, the maximum flow problem is formulated in . After solving , for any edge $(v_i^m, v_j^m), v_i^m\in V_O, v_j^m\in V_R$, $f_{i,j}=1$ indicates that $v_j^m$ is assigned to $v_i^m$. If $f_{i,j}=0, v_j^m\in V_R$, $v_j^m$ is not assigned to any original via. Therefore, $v_j$ will not be manufactured.

\[prbl:max\_flow\] $$\begin{aligned}
    \max  &\hspace{1em} \sum\limits_{(v_i^m, v_j^m)\in E_m} f_{i,j} & \label{eq:mf_obj} \\
    \text{s.t.}   &\hspace{1em} \sum\limits_{v_i^m:(v_i^m, v_j^m)\in E_m} f_{i,j}= \sum\limits_{v_i^m:(v_j^m, v_i^m)\in E_m} f_{j,i}, &\forall v_j^m\in V_m\backslash \{s,t\} \\
    &\hspace{1em} 0\leq f_{i,j}\leq c_{i,j}, &\forall (v_i^m, v_j^m)\in E_m.  \label{eq:mf_cap}
    \end{aligned}$$

On the other hand, if a minimum distance $d$ is given, $E_c$ is constructed as follows. For each pair of vias $v_i$ and $v_j$, their distance is less than $d$, we say they are in conflict and an edge $e\in E_c$ is created to connect $v_i^c$ and $v_j^c$. If $G_c$ is bipartite, the via layer can be printed with DPL. Otherwise, to meet the distance requirement, we have to re-assign the redundant vias and/or delete a set of assigned redundant vias by solving an odd cycle cover problem.

To make sure that $G_c$ is bipartite, each $e\in E_c$, connecting $v_i^c$ and $v_j^c$, must meet the constraints  [@Jensen2005Experimental], where $x_i^c$ indicates that $v_i^c$ should be deleted (1) or not (0); $s_i$ is the color of $v_i^c$’s. By assigning different colors, the vias can be printed with two masks. Note that $s_i$ does not have to be memorized since a bipartite graph can be bi-colored in linear time.

\[prbl:bi\] $$\begin{aligned}
    &\hspace{1em} s_i + s_j + ( x_i^c + x_j^c ) \geq 1, &\forall (v_i^c, v_j^c) \in E_c \label{eq:bi1} \\
    &\hspace{1em} s_i + s_j - ( x_i^c + x_j^c ) \leq 1, &\forall (v_i^c, v_j^c) \in E_c \label{eq:bi2} \\
    &\hspace{1em} s_i\in \{0, 1\}, &\forall v_i^c\in V_c. \label{eq:color}
    \end{aligned}$$

Moreover, three more constraints are included to connect $G_m$ and $G_c$ as follows.

1.  Any original via must not be deleted in $G_c$.

2.  Any deleted redundant via must not be assign to any original via.

3.  Any redundant via that is not assigned must be deleted.

Overall, the redundant via insertion problem can formulated in an ILP form .  and  are used to formulate the three constraints mentioned above.

\[prbl:overall\] $$\begin{aligned}
    \max  &\hspace{1em} \sum\limits_{(v_i^m, v_j^m)\in E_m} f_{i,j} & \\
    \text{s.t.}   &\hspace{1em} \sum\limits_{v_i^m:(v_i^m, v_j^m)\in E_m} f_{i,j}= \sum\limits_{v_i^m:(v_j^m, v_i^m)\in E_m} f_{j,i}, &\forall v_j^m\in V_m\backslash \{s,t\}  \\
    &\hspace{1em} x_i^m=1-\sum\limits_{v_i^m:(v_i^m, v_j^m)\in E_m} f_{i,j}, &\forall v_i^m\in V_m \label{prbl:connect}\\
    &\hspace{1em} s_i + s_j + ( x_i^c + x_j^c ) \geq 1, &\forall (v_i^c, v_j^c) \in E_c \\
    &\hspace{1em} s_i + s_j - ( x_i^c + x_j^c ) \leq 1, &\forall (v_i^c, v_j^c) \in E_c \\
    &\hspace{1em} x_i^c = 1 - \sum\limits_{v_i^m:(v_i^m, v_j^m)\in E_m}, &\forall v_i\in V_A \\
    &\hspace{1em} x_i^c=0, &\forall v_i^c\in V_O \label{prbl:vo}\\
    &\hspace{1em} x_i^c\in \{0,1\}, &\forall v_i^c\in V_R. \\
    &\hspace{1em} f_{i,j}\in \{0,1\}, & \forall (v_i^m, v_j^m)\in E_m\\
    &\hspace{1em} s_i\in \{0, 1\}, &\forall v_i^c\in V_c.
    \end{aligned}$$
