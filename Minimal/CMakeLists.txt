cmake_minimum_required(VERSION 2.8)

project(Minimal)
if (NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

find_package(OpenGL)
find_package(SDL)
include_directories(
	${OPENGL_INCLUDE_DIRS}
	${SDL_INCLUDE_DIR}
)

file(GLOB_RECURSE SRCS src/*.cpp src/*.h)

add_executable(Minimal MACOSX_BUNDLE ${SRCS})
target_link_libraries(Minimal
	${OPENGL_LIBRARIES}
	${SDL_LIBRARY}
)
