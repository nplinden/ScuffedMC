cmake_minimum_required(VERSION 3.27.8)
project(MyMC VERSION 0.1)
set(TARGET MyMC)
configure_file(inc/config.h.in inc/config.h)
find_package (Eigen3 3.4 REQUIRED NO_MODULE)

include_directories(inc)
# add_subdirectory(src)
add_executable(${TARGET} src/main.cpp 
                         src/particle.cpp 
                         src/plane.cpp 
                         src/sphere.cpp 
                         src/cylinder.cpp
                         src/halfspace.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/inc)
target_link_libraries (${PROJECT_NAME} Eigen3::Eigen)
# target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/src)

