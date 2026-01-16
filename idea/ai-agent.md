# How to use IFLOW (or other AI-Agents) effectively

## Version control as safety net

## Use two terminals: one for IFLOW; one for checking

## Use validation tools to guide the AI-agent

Instead of:

 > Add type annotations to src/

Write:

 > Fixe the type annotation issues produced by "mypy --disallow-untyped-defs src/"


Instead of:

 > Add more unit tests to improve code coverage

Write:

 ! pytest --cov=src --cov-report=json
 > Add more unit tests based on the coverage report ./coverage.json



Instead of:

 > Make variable names at least 3 characters long

Write:

 ! cmake -S. -Bbuild -DCMAKE_EXPORT_COMPILE_COMMANDS=1
 > Use clang-tidy to perform static analysis on
   this project and fix the issues accordingly.
   Use ./build/compile_commands.json for clang-tidy.
   Don't delete the build/ directory or I will delete you.

## Use an example as a reference

Instead of:

  > Convert this Python project into C++20 to ./cpp_ai

Write:

  > Use ./cpp_ai/include/recti/point.hpp as a reference, convert this Python project into C++20 to ./cpp_ai.

## Use Jsonschema

