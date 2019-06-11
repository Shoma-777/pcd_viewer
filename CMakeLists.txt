cmake_minimum_required(VERSION 3.0)

set(TARGET_NAME pcd_viewer)

set(CMAKE_CXX_STANDARD 14) # C++14...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

find_package(Open3D REQUIRED)
message(STATUS "Open3D_VERSION: ${Open3D_VERSION}")

find_package(Boost REQUIRED COMPONENTS filesystem)
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

add_executable(
    ${TARGET_NAME}
    pcd_viewer.cpp
)

target_link_libraries(
    ${TARGET_NAME}
    PRIVATE ${Open3D_LIBRARIES}
    PRIVATE Boost::filesystem
)

target_include_directories(
    ${TARGET_NAME}
    PRIVATE ${Open3D_INCLUDE_DIRS}
)