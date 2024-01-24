add_library(MyLibAPI INTERFACE )
target_include_directories(MyLibAPI INTERFACE   "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                                                "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>")

add_library(MyLib)

target_sources(MyLib PUBLIC "include/mylib/export.hpp"
                     PRIVATE    "src/mylib.cpp"
                                "src/mylib_impl.cpp"
                                "src/privlib.h"
                                "src/privlib.cpp")
                                
target_link_libraries(MyLib PRIVATE MyLibAPI)

target_include_directories(MyLib PUBLIC 
                            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                            "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>"
                            PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")


set_target_properties(MyLib PROPERTIES
                        PUBLIC_HEADER "${PUBLIC_HEADER_FILES}"
                        DEBUG_POSTFIX "d"
                        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(MSVC)
	target_compile_options(MyLib PUBLIC /wd4251 /wd4275 PRIVATE /W4)
	set_target_properties(MyLib PROPERTIES LINK_FLAGS "/ignore:4099")
endif()

if(NOT BUILD_SHARED_LIBS)
    string(TOUPPER MyLib PROJECT_NAME_UPPER)
    set_target_properties(MyLib PROPERTIES COMPILE_FLAGS -D${PROJECT_NAME_UPPER}_STATIC)
endif()

include(GenerateExportHeader)
string(TOUPPER MyLib PROJECT_NAME_UPPER)
generate_export_header(MyLib
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/mylib/export.hpp
    EXPORT_MACRO_NAME ${PROJECT_NAME_UPPER}_EXPORT
    STATIC_DEFINE ${PROJECT_NAME_UPPER}_STATIC
)