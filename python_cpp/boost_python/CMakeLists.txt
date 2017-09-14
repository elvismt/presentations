#
# Copyright (C) 2017  Elvis M. Teixeira
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 2.8)
project(BoostPythonDemo)

# Find necessary packages
find_package(PythonLibs 3.5 REQUIRED)
find_package(Boost COMPONENTS python-py35 REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

if (NOT WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

# Build our library
add_library(hello SHARED library.cpp module.cpp)
target_link_libraries(hello ${Boost_LIBRARIES})
# Prevent the lib prefix (like libhello.so)
set_target_properties(hello PROPERTIES PREFIX "")
