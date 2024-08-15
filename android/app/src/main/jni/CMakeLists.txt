cmake_minimum_required(VERSION 3.13)

# Define the library name here.
project(appmodules)

# This file includes all the necessary to let you build your application with the New Architecture.
include(${REACT_ANDROID_DIR}/cmake-utils/ReactNative-application.cmake)
# App needs to add and link against tm (TurboModules) folder
add_subdirectory(${REACT_ANDROID_DIR}/../../../tm/ tm_build)
target_link_libraries(${CMAKE_PROJECT_NAME} tm)