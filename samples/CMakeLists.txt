######################
## PROJECT SETTINGS ##
######################

## DEFINE MAIN PATHS
set(bin_path ${PROJECT_BINARY_DIR})
set(source_path ${PROJECT_SOURCE_DIR}/src)

find_package(OpenCV 3.2 REQUIRED)

## compile all files
file(GLOB SAMPLE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# make all the samples bins
foreach(sample_src ${SAMPLE_FILES})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(sample_name ${sample_src} NAME_WE)

        #Add compile target
        add_executable(${sample_name} ${sample_src})

        #link libraries
        target_link_libraries(${sample_name} ${OpenCV_LIBS})

        #I like to move binaries to bin_path
        set_target_properties(${sample_name} PROPERTIES
                              RUNTIME_OUTPUT_DIRECTORY ${bin_path})

        install(TARGETS ${sample_name}
                RUNTIME DESTINATION bin)
endforeach(sample_src)
