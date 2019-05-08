project(Packing)
cmake_minimum_required(VERSION 2.8)
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(LIB_SOURCES
    src/random/ARandom.cxx
    src/random/RandomUniform.cxx
    src/random/RandomFactory.cxx

    src/core/Data.cxx
    src/core/Point.cxx
    src/core/Math.cxx

    src/search/ASearch.cxx
    src/search/SearchUnform.cxx
    src/search/SearchFactory.cxx

    src/algorithm/AAlgorithm.cxx
    src/algorithm/AlgorithmFactory.cxx
    src/algorithm/SpherePackingAlgorithm.cxx





    src/IO/Reader.cxx
    src/IO/Writer.cxx
)
set(LIB_HEADERS
    src/core/Constants.h
    src/random/ARandom.h
    src/random/RandomUniform.h
    src/random/RandomFactory.h


    src/core/Data.h
    src/core/Point.h
    src/core/Math.h

    src/search/ASearch.h
    src/search/SearchUnform.h
    src/search/SearchFactory.h

    src/algorithm/AAlgorithm.h
    src/algorithm/AlgorithmFactory.h
    src/algorithm/SpherePackingAlgorithm.h


    src/IO/Reader.h
    src/IO/Writer.h
)
include_directories(${PROJECT_SOURCE_DIR}/src)


ADD_LIBRARY( libPacking STATIC ${LIB_SOURCES} ${LIB_HEADERS} )
add_executable(Packing src/app/main.cxx)
target_link_libraries(Packing  ${VTK_LIBRARIES} -lpthread -lboost_log -lstdc++fs  libPacking)

add_executable(MathTests src/app/MathTests.cxx)
target_link_libraries(MathTests  ${VTK_LIBRARIES} -lpthread -lboost_log -lstdc++fs  libPacking)


