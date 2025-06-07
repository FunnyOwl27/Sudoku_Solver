# CMakeList.txt : CMake project for Sudoku_Solver, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.

project ("Sudoku_Solver")

# Add source to this project's executable.
add_executable (Sudoku_Solver "src/main.cpp" "src/Sudoku_Solver.cpp" "src/Sudoku_Solver.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sudoku_Solver PROPERTY CXX_STANDARD 11)
endif()

# TODO: Add tests and install targets if needed.
