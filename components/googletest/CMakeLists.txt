set(srcs 
    "libs/googletest/googletest/src/gtest_main.cc"
    "libs/googletest/googletest/src/gtest-all.cc"
    "libs/googletest/googletest/src/gtest-assertion-result.cc"
    "libs/googletest/googletest/src/gtest-death-test.cc"
    "libs/googletest/googletest/src/gtest-filepath.cc"
    "libs/googletest/googletest/src/gtest-matchers.cc"
    "libs/googletest/googletest/src/gtest-port.cc"
    "libs/googletest/googletest/src/gtest-printers.cc"
    "libs/googletest/googletest/src/gtest-test-part.cc"
    "libs/googletest/googletest/src/gtest-typed-test.cc"
    "libs/googletest/googletest/src/gtest.cc"
    "libs/googletest/googlemock/src/gmock_main.cc"
    "libs/googletest/googlemock/src/gmock-all.cc"
    "libs/googletest/googlemock/src/gmock-cardinalities.cc"
    "libs/googletest/googlemock/src/gmock-internal-utils.cc"
    "libs/googletest/googlemock/src/gmock-matchers.cc"
    "libs/googletest/googlemock/src/gmock-spec-builders.cc"
    "libs/googletest/googlemock/src/gmock.cc"
    )
set(inc
"libs/googletest/googletest/include"
"libs/googletest/googletest"
"libs/googletest/googlemock/include"
"libs/googletest/googlemock"
)
idf_component_register(SRCS ${srcs} 
INCLUDE_DIRS ${inc}
REQUIRES pthread)