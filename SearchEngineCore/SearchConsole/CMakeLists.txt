cmake_minimum_required(VERSION 3.9)
set (CMAKE_CXX_STANDARD 11)
project(SearchEngine)
include_directories(../PreProcessing/include ../Indexing/include)
set(SOURCES ../PreProcessing/src/wordlist.cpp ../PreProcessing/src/parser.cpp ../Indexing/src/Tree.cpp ../Indexing/src/Node.cpp ../Indexing/src/Cloud.cpp engine.cpp)
add_executable(engine ${SOURCES})
target_link_libraries(engine)