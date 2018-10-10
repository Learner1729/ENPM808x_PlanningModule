find_package(SDL2 REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

add_executable(shell-app main.cpp)

target_link_libraries(shell-app ${SDL2_LIBRARIES})
