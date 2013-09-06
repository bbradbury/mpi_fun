cmake_minimum_required (VERSION 2.6)
project (MpiFun)

add_executable(mpi_fun src/main/main.cpp)
add_executable(stl_refresher src/main/stl_refresher.cpp)

include_directories ("${PROJECT_SOURCE_DIR}/src/")
add_library(pi src/mpi_fun/pi/pi_calc.cpp)


SET(LIBRARY_OUTPUT_PATH  ${MpiFun_BINARY_DIR}/lib CACHE PATH "Single directory for all libraries." )
SET( EXECUTABLE_OUTPUT_PATH ${MpiFun_BINARY_DIR}/bin CACHE PATH "Single directory for all executables." )
MARK_AS_ADVANCED( EXECUTABLE_OUTPUT_PATH )
MARK_AS_ADVANCED( LIBRARY_OUTPUT_PATH )

#SET(CMAKE_C_COMPILER mpicc)
#SET(CMAKE_CXX_COMPILER mpicxx)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -stdlib=libc++")
target_link_libraries(mpi_fun pi)
target_link_libraries(mpi_fun mpi m mpi_cxx)

target_link_libraries(stl_refresher pi)
