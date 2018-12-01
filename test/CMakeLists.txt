set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/VisualizeMapSDL.cpp
    ../app/AStar.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include
										   ../vendor/googletest/googlemock/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${SDL2_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC )
target_link_libraries(cpp-test PUBLIC gtest gmock ${SDL2_LIBRARIES})
