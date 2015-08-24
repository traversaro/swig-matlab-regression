cmake_minimum_required(VERSION 2.8.11)

project(refToInternalObject CXX)

find_package(SWIG REQUIRED)
include(UseSWIG)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


add_library(refToInternalObjectLib SHARED refToInternalObject.cpp)

# Find MATLAB
find_package(Matlab
             REQUIRED
             MX_LIBRARY
             MAIN_PROGRAM)

include_directories(${Matlab_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

set_source_files_properties(refToInternalObject.i PROPERTIES CPLUSPLUS ON)
swig_add_module(refToInternalObjectMATLAB_wrap matlab refToInternalObject.i)
target_link_libraries(refToInternalObjectMATLAB_wrap refToInternalObjectLib)

set_target_properties(refToInternalObjectMATLAB_wrap PROPERTIES PREFIX "" SUFFIX .${Matlab_MEX_EXTENSION})

#On new versions of Clang, MATLAB requires C++11.
#I enable it on all Clangs
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        if (${CMAKE_GENERATOR} MATCHES "Xcode")
            #this should set explictly the option in xcode. Unfortunately it does not work.
            set(XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "C++11")
        endif(${CMAKE_GENERATOR} MATCHES "Xcode")
    endif(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
