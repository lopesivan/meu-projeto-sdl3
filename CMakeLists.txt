cmake_minimum_required(VERSION 3.20)
project(exemplo_cpp_configurado CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------------
# Opções de build para debug
# ----------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependência instalada via Conan (CMakeDeps gera o Config no build/)
find_package(SDL3 REQUIRED CONFIG)

# Executável
add_executable(app_example main.cpp)
target_link_libraries(app_example PRIVATE SDL3::SDL3)
