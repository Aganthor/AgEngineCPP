cmake_minimum_required(VERSION 3.12)

project(AgEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

add_executable(AgEngine main.cpp Game.cpp)

#SFML linking and include
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

#Need to find and link OpenGL for imgui stuff
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    message("opengl found")
    message("include dir: " ${OPENGL_INCLUDE_DIR})
    message("link libraries: " ${OPENGL_LIBRAIRIES})
else (OPENGL_FOUND)
    message("opengl not found")
endif()

# Include the libnoise library for perlin noise :)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
#find_package(LibNoise)
#if(LIBNOISE_FOUND)
#  include_directories(LIBNOISE_INCLUDE_DIR)
#endif()

#Include SOL2 header files
include_directories(${CMAKE_SOURCE_DIR}/sol2/include)

#Include ImGUI to the project.
include_directories(${CMAKE_SOURCE_DIR}/imgui)

add_subdirectory(imgui)
#add_subdirectory(noiseutils)
add_subdirectory(FastNoise)
add_subdirectory(ECS)
add_subdirectory(map)

target_link_libraries(AgEngine ${OPENGL_LIBRARIES} sfml-audio sfml-graphics sfml-window sfml-system imgui ecs map fastnoise)

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
