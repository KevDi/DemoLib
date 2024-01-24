add_library(Consumer)

target_link_libraries(Consumer PRIVATE MyLib)

target_sources(Consumer PUBLIC "include/consumer/consumer.h"
                                "include/consumer/export.hpp"
                                PRIVATE "src/consumer.cpp")

target_include_directories(Consumer PUBLIC 
                            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                            "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>"
                            PRIVATE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")


set_target_properties(Consumer PROPERTIES
                        PUBLIC_HEADER "${PUBLIC_HEADER_FILES}"
                        DEBUG_POSTFIX "d"
                        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(MSVC)
	target_compile_options(Consumer PUBLIC /wd4251 /wd4275 PRIVATE /W4)
	set_target_properties(Consumer PROPERTIES LINK_FLAGS "/ignore:4099")
endif()

if(NOT BUILD_SHARED_LIBS)
    string(TOUPPER Consumer PROJECT_NAME_UPPER)
    set_target_properties(Consumer PROPERTIES COMPILE_FLAGS -D${PROJECT_NAME_UPPER}_STATIC)
endif()

include(GenerateExportHeader)
string(TOUPPER Consumer PROJECT_NAME_UPPER)
generate_export_header(Consumer
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/consumer/export.hpp
    EXPORT_MACRO_NAME ${PROJECT_NAME_UPPER}_EXPORT
    STATIC_DEFINE ${PROJECT_NAME_UPPER}_STATIC
)