cmake_minimum_required(VERSION 3.12)
project(gegelapylib)


# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Boost libraries
find_package(Boost REQUIRED COMPONENTS python)


# *******************************************
# *********** GEGELATI LIBRARY **************
# *******************************************

if(WIN32)
	set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    # find the gegelatilib-x.y.z folder in the lib directory.
	file(GLOB GEGELATI_ROOT_DIR "${LIBS_DIR}/gegelatilib-[\\.|0-9]*")
	set(ENV{GEGELATI_DIR} ${GEGELATI_ROOT_DIR})
endif()
find_package(GEGELATI)


if (WIN32)
	file(GLOB
		GEGELATI_DLL
		${GEGELATI_ROOT_DIR}/bin/*.dll
	)

	MESSAGE("Copy GEGELATI DLLs into ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
	if(NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio.*")
		file(COPY ${GEGELATI_DLL} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
	else()
		file(COPY ${GEGELATI_DLL} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
		file(COPY ${GEGELATI_DLL} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release)
	endif()
endif()

# Find Python 
# Find Python
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Specify the Python library directories
link_directories(${Python3_LIBRARY_DIRS})


# Include directories
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${GEGELATI_INCLUDE_DIRS}
    ${Python3_INCLUDE_DIRS}
)

# Add the Boost.Python module source file
# Get all the .cpp source files recursivelyg
file(GLOB_RECURSE SOURCES "gegelapy_wrapper/*.cpp")

# Create the shared library for the Boost.Python module
add_library(gegelapy MODULE ${MODULE_SOURCE} ${SOURCES})

# Link the Boost libraries
target_link_libraries(gegelapy PRIVATE ${Boost_LIBRARIES} ${GEGELATI_LIBRARIES})

# Set the output name and location of the Python module
set_target_properties(gegelapy PROPERTIES
    OUTPUT_NAME "gegelapy"
)

# Set the appropriate extension for the Python module on Windows
if(WIN32)
    set_target_properties(gegelapy PROPERTIES
        SUFFIX ".pyd"
    )
endif()
