cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(ESMReader)
set(CMAKE_CXX_STANDARD 20)

option(BUILD_TESTS "Build tests for the ESM Reader" ON)

set(ESM_SRC
	${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/types.h

	${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/bufferstream.h
	${CMAKE_CURRENT_LIST_DIR}/src/bufferstream.cpp

	${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/esm.h
	${CMAKE_CURRENT_LIST_DIR}/src/esm.cpp

    # Records
	${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/records/baserecord.h
	${CMAKE_CURRENT_LIST_DIR}/src/records/baserecord.cpp
    
	${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/records/tes4record.h
	${CMAKE_CURRENT_LIST_DIR}/src/records/tes4record.cpp

    # Sub Records
	${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/subrecords/basesubrecord.h
	${CMAKE_CURRENT_LIST_DIR}/src/subrecords/basesubrecord.cpp

    ${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/subrecords/common.h
	${CMAKE_CURRENT_LIST_DIR}/src/subrecords/common.cpp

)

add_library(${PROJECT_NAME} STATIC ${ESM_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/inc/esmreader/types.h)

# Used with permission from:
# https://github.com/craftablescience/studiomodelpp/blob/main/CMakeLists.txt#L32
if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0)
    FetchContent_MakeAvailable(googletest)
    enable_testing()

    set(TEST_RESOURCES_ROOT_PATH "${CMAKE_CURRENT_LIST_DIR}/test/res/")
    configure_file("${CMAKE_CURRENT_LIST_DIR}/test/config.h.in" "${CMAKE_CURRENT_LIST_DIR}/test/config.h")

    add_executable(${PROJECT_NAME}Test 
        "${CMAKE_CURRENT_LIST_DIR}/test/f3_anchorage.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/test/fnv_honesthearts.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/test/main.cpp"
    )
    target_link_libraries(${PROJECT_NAME}Test PUBLIC ${PROJECT_NAME} gtest_main)

	include(GoogleTest)
	gtest_discover_tests(${PROJECT_NAME}Test)
endif()