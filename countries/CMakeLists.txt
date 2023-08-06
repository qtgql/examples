cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(countries VERSION 0.1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(3rdparty/qtgql)
add_subdirectory(src/graphql/__generated__)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

file(GLOB_RECURSE HEADERS "src/*.hpp")

find_package(Qt6 REQUIRED COMPONENTS Core Quick)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE qtgql::qtgql
        Qt6::Core Qt6::Quick Countries
        )

