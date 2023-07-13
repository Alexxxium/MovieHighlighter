cmake_minimum_required(VERSION 3.5)

project(CMakeMovie VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(
 frontend/include
 frontend/forms
 backend/include
 controller/include
 patterns
)

set(PROJECT_SOURCES
        main.cpp

        frontend/forms/mainwindow.ui
        frontend/forms/AddNewGame.ui
        frontend/include/mainwindow.h
        frontend/include/AddNewGame.h
        frontend/source/AddNewGame.cpp
        frontend/source/mainwindow.cpp

        backend/include/Movie.h
        backend/include/MovieCore.h
        backend/include/MovieExceptions.h
        backend/source/Movie.cpp
        backend/source/MovieCore.cpp
        backend/source/MovieExceptions.cpp

        controller/include/Controller.h
        controller/source/Controller.cpp

        patterns/WaiteQueue/WaiteQueue.h
        patterns/WaiteQueue/WaiteQueue.inl
        patterns/WaiteQueue/WaiteQueue.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CMakeMovie
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(CMakeMovie SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(CMakeMovie
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CMakeMovie PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(CMakeMovie ${OpenCV_LIBS})

set_target_properties(CMakeMovie PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CMakeMovie)
endif()
