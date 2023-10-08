cmake_minimum_required(VERSION 3.5)

project(MovieHighlighter)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Widgets DBus REQUIRED)



include_directories(
    ${OpenCV_INCLUDE_DIRS} 
    frontend/include 
    frontend/forms 
    frontend/forms/generate
    backend/include 
    controller/include 
    patterns 
)

set(PROJECT_SOURCES
    main.cpp
    frontend/source/AddNewGame.cpp
    frontend/source/mainwindow.cpp
    backend/source/Movie.cpp
    backend/source/MovieCore.cpp
    backend/source/MovieExceptions.cpp
    controller/source/Controller.cpp
    patterns/TaskQueue.cpp 
    patterns/WaiteQueue/WaiteQueue.cpp 

    #Generated files
    frontend/forms/generate/moc_mainwindow.cpp
    frontend/forms/generate/moc_Movie.cpp
    frontend/forms/generate/qrc_${PROJECT_NAME}.cpp
    frontend/forms/generate/moc_AddNewGame.cpp
    frontend/forms/generate/moc_Controller.cpp
)


add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} Qt5::Widgets Qt5::DBus)
