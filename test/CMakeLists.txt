file(GLOB_RECURSE TEST *.cpp)

file(GLOB_RECURSE TSOURCE ../src/*.cpp)
list(REMOVE_ITEM TSOURCE ../src/main.cpp)

add_executable(tests ${TEST} ${TSOURCE})
