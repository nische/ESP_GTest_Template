cmake_minimum_required(VERSION 3.5)
project(unit_tests)

set(RunTesting TRUE) #Need to set if you want to build the Mocks in idf_cpp_wrapper

#https://github.com/espressif/esp-idf/blob/master/tools/cmake/scripts/component_get_requirements.cmake
function(idf_component_register)
    get_filename_component(__name "${CMAKE_CURRENT_LIST_DIR}" NAME)
    message(STATUS "idf_component_register (for nativ): ${__name}")

    set(options WHOLE_ARCHIVE)
    set(single_value KCONFIG KCONFIG_PROJBUILD)
    set(multi_value SRCS SRC_DIRS EXCLUDE_SRCS
                    INCLUDE_DIRS PRIV_INCLUDE_DIRS LDFRAGMENTS REQUIRES
                    PRIV_REQUIRES REQUIRED_IDF_TARGETS EMBED_FILES EMBED_TXTFILES)
    cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}" "${ARGN}")

    list(TRANSFORM __INCLUDE_DIRS PREPEND "${CMAKE_CURRENT_LIST_DIR}/")#Fix include dir with path

    include_directories(${__INCLUDE_DIRS})
    add_library(${__name} STATIC ${__SRCS})
    target_link_libraries(${__name} PUBLIC ${__REQUIRES})
    target_link_libraries(${__name} PRIVATE ${PRIV_REQUIRES})
    #target_include_directories(${__name} INTERFACE ${__INCLUDE_DIRS}) TODO: Need to look whats better
    target_include_directories(${__name} PUBLIC ${__INCLUDE_DIRS})

    GET_PROPERTY(extra_libs GLOBAL PROPERTY EXTRA_LIBS)
    list(APPEND extra_libs ${__name})
    SET_PROPERTY(GLOBAL PROPERTY EXTRA_LIBS ${extra_libs})

    return()
endfunction()

# Search all Componets and add as Subdirectory:
file(GLOB COMPONENT_DIRS LIST_DIRECTORIES true "../components/*/CMakeLists.txt")
foreach(ENTRY IN LISTS COMPONENT_DIRS)  
    get_filename_component(dir "${ENTRY}" PATH)
    get_filename_component(comp "${dir}" NAME) 
    message(STATUS "Include ${comp} in ./components/${comp}")
    add_subdirectory(${dir} ./components/${comp})
endforeach()

#Get List of Registered Componets 
GET_PROPERTY(extra_libs GLOBAL PROPERTY EXTRA_LIBS)
#message(STATUS "Registered Components: ${extra_libs}")

#Get all Testfiles:
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true "../components/*.test.cpp")


#Build Executable and link libs:
add_executable(unit_tests testrunner.cpp ${TEST_SOURCES})
target_link_libraries(unit_tests PUBLIC ${extra_libs})