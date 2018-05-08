cmake_minimum_required(VERSION 2.8)
project(samples)

######################
## PROJECT SETTINGS ##
######################

## DEFINE MAIN PATHS
set(bin_path ${PROJECT_BINARY_DIR}/bin)
set(source_path ${PROJECT_SOURCE_DIR}/src)

find_package(OpenCV 3.4 REQUIRED)

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
endforeach(sample_src)
