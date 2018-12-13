CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(assembly)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -Wall -m64 -pipe -std=c++11 -lrt -Wno-reorder -Wdeprecated-declarations -pthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -std=c++11 -pthread")

AUX_SOURCE_DIRECTORY(. SOURCE_FILES)
ADD_EXECUTABLE(assembly ${SOURCE_FILES})

INCLUDE_DIRECTORIES(src/thread)
#LINK_DIRECTORIES(src/thread)
TARGET_LINK_LIBRARIES(assembly thread)
ADD_DEFINITIONS(-DSPIN_MUTEX)
ADD_SUBDIRECTORY(src/thread)

