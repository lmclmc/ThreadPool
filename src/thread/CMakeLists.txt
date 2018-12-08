CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -Wall -m64 -pipe -std=c++11 -lrt -Wno-reorder -Wdeprecated-declarations -pthread")

aux_source_directory(.  SOURCE_THREAD_FILES)
ADD_LIBRARY(thread ${SOURCE_THREAD_FILES})
