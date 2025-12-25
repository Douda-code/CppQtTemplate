cmake_minimum_required(VERSION 3.20)

project(MyTemplate VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "C:/Qt/6.10.1/msvc2022_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(engine)

# --- Generic Template Setup ---
set(APP_NAME ${PROJECT_NAME})

add_executable(${APP_NAME} src/main.cpp)
target_link_libraries(${APP_NAME} PRIVATE Core Qt6::Widgets)
set_target_properties(${APP_NAME} PROPERTIES WIN32_EXECUTABLE ON)
