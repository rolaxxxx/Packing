project(Packing)
cmake_minimum_required(VERSION 2.8)
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -Wall -O3")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(LIB_SOURCES
    src/random/ARandom.cxx
    src/random/RandomUniform.cxx
    src/random/RandomFactory.cxx
    src/random/RandomDiscrete.cxx

    src/core/Data.cxx
    src/core/Point.cxx
    src/core/Math.cxx

    src/search/ASearch.cxx
    src/search/SearchUnform.cxx
    src/search/SearchFactory.cxx


    src/algorithm/AAlgorithm.cxx
    src/algorithm/AlgorithmFactory.cxx
    src/algorithm/SpherePackingAlgorithm.cxx


    src/Boundaries/BBoundaries.cxx
    src/Boundaries/BoundariesFactory.cxx
    src/Boundaries/CubeShape.cxx
    src/Boundaries/cylindershape.cpp
    src/Boundaries/Mesh.cpp
    src/Boundaries/Mesh.h

    src/IO/Reader.cxx
    src/IO/Writer.cxx
)
set(LIB_HEADERS
    src/core/Constants.h
    src/random/ARandom.h
    src/random/RandomUniform.h
    src/random/RandomFactory.h
    src/random/RandomDiscrete.h

    src/core/Data.h
    src/core/Point.h
    src/core/Math.h
    src/core/time.h
    src/core/json_reader.h

    src/search/ASearch.h
    src/search/SearchUnform.h
    src/search/SearchFactory.h


    src/algorithm/AAlgorithm.h
    src/algorithm/AlgorithmFactory.h
    src/algorithm/SpherePackingAlgorithm.h


    src/Boundaries/BBoundaries.h
    src/Boundaries/BoundariesFactory.h
    src/Boundaries/CubeShape.h
    src/Boundaries/cylindershape.h

    src/IO/Reader.h
    src/IO/Writer.h
)
include_directories(${PROJECT_SOURCE_DIR}/src)


ADD_LIBRARY( libPacking STATIC ${LIB_SOURCES} ${LIB_HEADERS} )
add_executable(Packing src/app/main.cxx)
target_link_libraries(Packing  ${VTK_LIBRARIES}   libPacking)

add_executable(MathTests src/app/MathTests.cxx)
target_link_libraries(MathTests  ${VTK_LIBRARIES}    libPacking)


