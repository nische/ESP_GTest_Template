if(RunTesting)
message( STATUS "BuildMocks" )
    set(srcs
        "Mocks/System/ChipInfoMock.h"
    )
    set(req
       
    )
    set(inc
        
    )
else()
    message(STATUS "DontBuildMocks")
    set(req

    )
    set(srcs 
        "ESP/system/ChipInfo.cpp"
        )
    set(inc
        "ESP/System"   
    )
endif()

set(interfaces
    "Interfaces/System"
)

idf_component_register(SRCS ${srcs} 
INCLUDE_DIRS ${inc} ${interfaces}
REQUIRES ${req})