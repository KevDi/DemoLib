add_executable(app src/main.cpp)

target_link_libraries(app PRIVATE MyLib Consumer)

set_target_properties(app PROPERTIES 
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)