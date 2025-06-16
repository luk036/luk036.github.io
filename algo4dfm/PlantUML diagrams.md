Here are the PlantUML diagrams for the `EllCalc` class based on the provided Python code:

### Class Diagram
```plantuml
@startuml EllCalcClassDiagram

class EllCalc {
    + {static} use_parallel_cut: bool = true
    - _n_f: float
    - helper: EllCalcCore

    + __init__(n: int)
    + calc_single_or_parallel(beta, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
    + calc_single_or_parallel_central_cut(beta, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
    + calc_parallel(beta0: float, beta1: float, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
    + calc_bias_cut(beta: float, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
    + calc_single_or_parallel_q(beta, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
    + calc_parallel_q(beta0: float, beta1: float, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
    + calc_bias_cut_q(beta: float, tsq: float) -> Tuple[CutStatus, Optional[Tuple[float, float, float]]]
}

class EllCalcCore {
    This class handles the core mathematical calculations
    for ellipsoid transformations
}

enum CutStatus {
    Success
    NoSoln
    NoEffect
}

EllCalc "1" *-- "1" EllCalcCore : uses
EllCalc ..> CutStatus : returns

note right of EllCalc
    The EllCalc class is used for calculating ellipsoid parameters
    and has attributes for storing constants and configuration options.
    It provides methods for different types of cuts (single, parallel, central)
    and handles the logic for selecting the appropriate cut type.
end note

@enduml
```

### Sequence Diagram (for calc_single_or_parallel method)
```plantuml
@startuml EllCalcSequenceDiagram

actor Caller
participant EllCalc
participant EllCalcCore

Caller -> EllCalc : calc_single_or_parallel(beta, tsq)
alt if beta is single number
    EllCalc -> EllCalc : calc_bias_cut(beta, tsq)
else if beta is list and use_parallel_cut
    EllCalc -> EllCalc : calc_parallel(beta[0], beta[1], tsq)
else
    EllCalc -> EllCalc : calc_bias_cut(beta[0], tsq)
end

alt if calc_parallel called
    EllCalc -> EllCalcCore : calc_parallel_bias_cut()
else if calc_bias_cut called
    EllCalc -> EllCalcCore : calc_bias_cut()
end

EllCalc --> Caller : (CutStatus, Optional[Tuple])

@enduml
```

### State Diagram (for cut calculation logic)
```plantuml
@startuml EllCalcStateDiagram

[*] --> CheckInput
CheckInput --> SingleCut : if beta is single number
CheckInput --> ParallelCut : if beta is list and use_parallel_cut
CheckInput --> SingleCut : else (fallback)

state SingleCut {
    [*] --> ValidateBeta
    ValidateBeta --> NoSolution : if tsq < beta²
    ValidateBeta --> CalculateCut : else
    CalculateCut --> Success
}

state ParallelCut {
    [*] --> CheckBetaOrder
    CheckBetaOrder --> NoSolution : if beta1 < beta0
    CheckBetaOrder --> CheckTSQ
    CheckTSQ --> SingleCut : if tsq ≤ beta1²
    CheckTSQ --> CalculateParallelCut : else
    CalculateParallelCut --> Success
}

Success --> [*]
NoSolution --> [*]

@enduml
```

These diagrams visualize:
1. The class structure and relationships (Class Diagram)
2. The flow of a typical method call (Sequence Diagram)
3. The decision logic for cut calculations (State Diagram)

The diagrams show how the `EllCalc` class acts as a facade that delegates complex calculations to `EllCalcCore` while managing the high-level logic and status reporting. The state diagram particularly highlights the validation checks and different cut calculation paths.