/init -> GEMINI.md


Add more unit tests without modifying the existing source code in src/.
Add "const" whenever appropriate.
Add more documentation comments to include/recti/global_router.hpp.
... Use xmake instead of cmake for verification.

Add more documentation tests to comments without modifying any classes and functions except comments.
Use "pytest --doctest-modules src" for verification.

Fix the errors/warnings produced by "xmake"
Fix the errors/warnings produced by "flake8 src"
Fix the errors/warnings produced by "mypy src"
Fix the errors/warnings produced by "tox -e docs"
Fix the errors/warnings produced by "cargo clippy"
Fix the errors/warnings produced by "cmake --build build --target GenerateDocs"

Perform code optimization without modifying any existing unit tests.
Perform code refactoring without modifying any existing unit tests.
