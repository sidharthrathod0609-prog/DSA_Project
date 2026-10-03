cmake_minimum_required(VERSION 3.15)

project(BankManagementSystem CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Project source files
set(SOURCES
    src/DBClient.cpp
    src/BankRepository.cpp
)

# Main Bank Management Application
add_executable(BankManagementSystem
    src/main.cpp
    ${SOURCES}
)

# DSA & Business Logic Unit Tests
add_executable(test_dsa
    tests/test_dsa.cpp
    ${SOURCES}
)

# MongoDB Connection Test
add_executable(test_mongo
    tests/test_mongo_connection.cpp
    src/DBClient.cpp
)

# Check for MongoDB C++ Driver if present on system
find_package(mongocxx QUIET)
find_package(bsoncxx QUIET)

if(mongocxx_FOUND AND bsoncxx_FOUND)
    message(STATUS "MongoDB C++ Driver found. Linking mongocxx and bsoncxx...")
    target_link_libraries(BankManagementSystem PRIVATE mongo::mongocxx_shared mongo::bsoncxx_shared)
    target_link_libraries(test_mongo PRIVATE mongo::mongocxx_shared mongo::bsoncxx_shared)
else()
    message(STATUS "MongoDB C++ Driver not found in CMake path. Using CLI/bridge mode.")
endif()
