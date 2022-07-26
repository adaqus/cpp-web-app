cmake_minimum_required(VERSION 3.2.0)
project(simpleWebApp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# find_package(Crow)
# target_link_libraries(simpleWebApp PUBLIC Crow::Crow)

# include_directories(/usr/include/boost)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Crow/include)

add_executable(simpleWebApp main.cpp)

# link_directories(/usr/include)
# target_link_libraries(simpleWebApp boost_system)
# target_link_libraries(simpleWebApp pthread)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
