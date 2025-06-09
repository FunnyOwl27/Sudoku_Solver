cmake_minimum_required(VERSION 3.28)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

project ("Sudoku_Solver")

add_executable (Sudoku_Solver "src/main.cpp" "src/Sudoku_Solver.cpp" "src/Sudoku_Solver.h")
target_compile_features(Sudoku_Solver PRIVATE cxx_std_17)
target_link_libraries(Sudoku_Solver PRIVATE SFML::Graphics)