cmake_minimum_required(VERSION 3.16)

project(gis VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Positioning Location)

qt_standard_project_setup(REQUIRES 6.5)
add_subdirectory(3rdParty/qtgql)

qt_add_executable(books
    src/main.cpp
)

target_sources(books
    PUBLIC
    src/app.hpp
    PRIVATE
    src/app.cpp
)


add_subdirectory(src/graphql/__generated__/)



set_target_properties(books PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(books
    PRIVATE Qt6::Quick Qt6::Positioning Qt6::Location
    Books qtgql::qtgql
)
