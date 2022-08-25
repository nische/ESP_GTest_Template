#if(RunTesting)
message( STATUS "Build Test Kram\n" )
set(srcs 
    "../unit_tests/testrunner.cpp"
    "../components/testClass/unit_tests/TestPrintClass.test.cpp"
    )
idf_component_register(WHOLE_ARCHIVE TRUE
                    SRCS ${srcs}
                    INCLUDE_DIRS ""
                    REQUIRES googletest
                    )

#else()
#message(STATUS "Build Regular App\n")
#idf_component_register(SRCS "app.cpp"
#                    INCLUDE_DIRS ""
#                    REQUIRES )
#endif()