
# EDA Algorithm Development: 避坑指南 (Pitfall Guide)

## Core Philosophy

- **Electronic Design Automation**: Keep in mind that "Design cannot be automated" - human insight remains essential in the automation process.

## Data Type Considerations

### Coordinate Systems
- Use **integer types** for coordinates rather than floating-point
- Avoid floating-point representation for coordinates due to:
  - Energy inefficiency
  - Round-off errors that accumulate during computations

### Integer Overflow Prevention
- Consider using **64-bit integers** instead of 32-bit to prevent overflow problems in large-scale designs

## Global Routing Challenges

### High Fanout Nets
- Special handling required for nets with many connections
- Current suggestion: kd-tree data structure (investigation needed)

## Clock Tree Synthesis

### Bounded Skew Requirements
- Primary objective: **Minimize total wirelength** while maintaining skew bounds
- Trade-offs between skew control and wirelength optimization
