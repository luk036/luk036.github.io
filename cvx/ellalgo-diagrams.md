
### 1. Sequence Diagram (Cutting Plane Process)
```mermaid
sequenceDiagram
    participant CP as Cutting Plane
    participant SS as Search Space
    participant O as Oracle

    Note over CP: Initialization
    CP->>SS: Get xc()
    CP->>O: Query assess_feas(xc)
    
    alt Feasible Solution Found
        O-->>CP: None (Feasible)
        CP-->>SS: Return Solution
    else Need Cutting Plane
        O-->>CP: Some((gradient, cut_choice))
        CP->>SS: update_bias_cut(gradient)
        
        alt Update Success
            SS-->>CP: CutStatus::Success
            CP->>SS: Get new xc()
            CP->>O: Query again
        else No Solution/No Effect
            SS-->>CP: CutStatus::NoSoln/NoEffect
            CP-->>SS: Terminate
        end
    end
```

### 2. Class Diagram (Main Components)
```mermaid
classDiagram
    class CuttingPlane {
        +cutting_plane_feas()
        +cutting_plane_optim()
        +cutting_plane_optim_q()
    }

    class SearchSpace {
        <<trait>>
        +xc()
        +tsq()
        +update_bias_cut()
        +update_central_cut()
    }

    class OracleFeas {
        <<trait>>
        +assess_feas()
    }

    class OracleOptim {
        <<trait>>
        +assess_optim()
    }

    class Options {
        +max_iters
        +tolerance
    }

    CuttingPlane --> SearchSpace
    CuttingPlane --> OracleFeas
    CuttingPlane --> OracleOptim
    CuttingPlane --> Options
    SearchSpace <|-- SearchSpaceQ
```

### 3. Flowchart (Binary Search Process)
```mermaid
flowchart TD
    A["Start: (l, u)"] --> B{Check Tolerance}
    B -- Yes --> C["Return (u changed?, iters)"]
    B -- No --> D["Calculate m = l + (u-l)/2"]
    D --> E["Oracle.assess_bs(m)"]
    E -- Feasible --> F["Update u = m"]
    E -- Infeasible --> G["Update l = m"]
    F & G --> H[Increment iteration count]
    H --> B
```

### 4. State Diagram (CutStatus Transitions)
```mermaid
stateDiagram-v2
    [*] --> Success
    [*] --> NoSoln
    [*] --> NoEffect
    [*] --> Unknown
    
    Success --> NoSoln: Space too small
    Success --> NoEffect: Cut ineffective
    NoEffect --> Unknown: Retry with alt cut
    Unknown --> Success: Valid cut found
```

### Key Color Coding:
- **Cutting Plane**: Orange
- **Search Space**: Blue
- **Oracle**: Green
- **Data Flow**: Purple arrows
- **Control Flow**: Red diamonds (decisions)

These diagrams collectively visualize:
1. The dynamic interaction between components
2. The hierarchical structure of traits and implementations
3. The binary search logic flow
4. State transitions during cut updates

The sequence diagram emphasizes the iterative query-update cycle, while the class diagram shows the Rust trait architecture. The flowchart and state diagram provide complementary perspectives on algorithm control flow.

Here are the enhanced **colorful** Mermaid diagrams with explicit color coding for each component and interaction:


### Color Legend:
| Color       | Component               | Meaning                     |
|-------------|-------------------------|-----------------------------|
| `#ffaa00`   | Cutting Plane           | Algorithm control           |
| `#00ccff`   | Search Space            | State management            |
| `#00ff88`   | Oracle                  | Feasibility/optimization    |
| `#66ff66`   | Success/Feasible        | Positive outcome            |
| `#ff6666`   | Failure/Infeasible      | Negative outcome            |
| `#ff9933`   | Neutral/Retry           | Intermediate state          |
| `#cccccc`   | Config/Unknown          | Parameters or unknowns      |

These diagrams now visually distinguish components, outcomes, and data flows using **vibrant colors** while maintaining logical clarity.