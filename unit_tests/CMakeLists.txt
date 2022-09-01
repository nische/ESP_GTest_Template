cmake_minimum_required(VERSION 3.5)
project(unit_tests)

set(RunTesting)

#https://github.com/espressif/esp-idf/blob/master/tools/cmake/scripts/component_get_requirements.cmake
#TODO: Add all reg componet libs to global var and link it to unit_tests
function(idf_component_register)
    get_filename_component(__name "${CMAKE_CURRENT_LIST_DIR}" NAME)
    message(STATUS "idf_component_register (for nativ): ${__name}")

    # message(STATUS "Location: ${CMAKE_CURRENT_LIST_DIR}")
    set(options WHOLE_ARCHIVE)
    set(single_value KCONFIG KCONFIG_PROJBUILD)
    set(multi_value SRCS SRC_DIRS EXCLUDE_SRCS
                    INCLUDE_DIRS PRIV_INCLUDE_DIRS LDFRAGMENTS REQUIRES
                    PRIV_REQUIRES REQUIRED_IDF_TARGETS EMBED_FILES EMBED_TXTFILES)
    cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}" "${ARGN}")

    list(TRANSFORM __INCLUDE_DIRS PREPEND "${CMAKE_CURRENT_LIST_DIR}/")#Fix include dir with path
    # message(STATUS "Include: ${__INCLUDE_DIRS}")

    include_directories(${__INCLUDE_DIRS})
    add_library(${__name} STATIC ${__SRCS})
    target_link_libraries(${__name} PUBLIC ${__REQUIRES})
    target_link_libraries(${__name} PRIVATE ${PRIV_REQUIRES})
    target_include_directories(${__name} INTERFACE ${__INCLUDE_DIRS})

    return()
endfunction()

#TODO: add all comonents with cmake files
add_subdirectory(../components/googletest ./components/googletest)
add_subdirectory(../components/testClass ./components/testClass)


file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false "../components/*.test.cpp")

add_executable(unit_tests testrunner.cpp ${TEST_SOURCES})
target_link_libraries(unit_tests PUBLIC googletest testClass)