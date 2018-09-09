cmake_minimum_required(VERSION 3.12)

project(AgEngine VERSION 0.1 LANGUAGES CXX)

add_executable(AgEngine main.cpp Game.cpp)

find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

#Include SOL2 header files
include_directories(${CMAKE_SOURCE_DIR}/sol2/include)

add_subdirectory(ECS)

target_link_libraries(AgEngine sfml-audio sfml-graphics sfml-window sfml-system ecs)

#set (source "${CMAKE_SOURCE_DIR}/res")
#set (destination "${CMAKE_CURRENT_BINARY_DIR}/res")
#add_custom_command(
#    TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E make_directory ${destination} 
#)

#add_custom_command(
# TARGET ${PROJECT_NAME} POST_BUILD
## COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
# COMMAND ${CMAKE_COMMAND} -E copy_directory ${source} ${destination} 
# DEPENDS ${destination}
# COMMENT "symbolic link resources folder from ${source} => ${destination}"
#)

