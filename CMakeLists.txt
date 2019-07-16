cmake_minimum_required(VERSION 3.14)
project(cpp_examples)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES_FILES ScreenShot.hpp)

add_executable(cpp_examples main.cpp ${SOURCES_FILES})

# Add X11
find_package(X11 REQUIRED)
include_directories(${X11_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})

# Add opencv
find_package( OpenCV REQUIRED highgui)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})