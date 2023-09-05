cmake_minimum_required(VERSION 3.16)

project(gis VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Positioning Location)

qt_standard_project_setup(REQUIRES 6.5)
add_subdirectory(3rdParty/qtgql)

qt_add_executable(appgis
    src/main.cpp
)

target_sources(appgis
    PUBLIC
    src/app.hpp
    PRIVATE
    src/app.cpp
)


add_subdirectory(src/graphql/__generated__/)


qt_add_qml_module(appgis
    URI gis
    VERSION 1.0
    QML_FILES src/qml/main.qml
    src/qml/RootRect.qml
    src/qml/playground.qml
    src/qml/MapPinPoint.qml
)

set_target_properties(appgis PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appgis
    PRIVATE Qt6::Quick Qt6::Positioning Qt6::Location
    GisPoc qtgql::qtgql
)

install(TARGETS appgis
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
