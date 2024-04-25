Hardware/Software

## LLVM

clang \ / arm
Rust ----- llvm ir ----- x86-64
golang / \ RISC-V
\ CGRA ???

## 🦀 Rust (embedded, IoT)

🏿 CPU + GPIO + UART + USB + 🛜 Wi-Fi

- Memory model (stack, heap)
- Interrupt based concurrency
- Finite state machine (zero-abstraction cost)
- Hardware Abstraction Layer (HAL)
  - provided by hardware vendors
- RTOS (run-time operating system)
  - RadonOS
  - TockOS

## Testing/Debugging

- semi-hosting
- SWD (single wired debugging)
- JTAG
