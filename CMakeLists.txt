CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(cmake_training CXX)
message("project name is automaically set as: ${PROJECT_NAME}")

set(PROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)



find_package(Boost REQUIRED
  COMPONENTS
    context
    filesystem
    program_options
    regex
    system
    thread
)

if(Boost_FOUND)
  message (STATUS "Found Boost")
else()
  message(WARNING "Boost not found")
endif()

# find_package(OpenCV REQUIRED)
# if(OpenCV_FOUND)
#   message (STATUS "Found OpenCV")
# else(OpenCV_FOUND)
#   message(WARNING "OpenCV not found")
# endif()


set(cmake_training_SRC
  src/my_class.cpp
  src/my_main.cpp
)


set(cmake_training_HEADERS
  include/cmake_training/my_class.h
)

add_executable(main ${cmake_training_SRC} ${cmake_training_HEADERS})
target_include_directories(main PUBLIC include/cmake_training ${BOOST_INCLUDE_DIRS})
target_link_libraries(main PUBLIC ${Boost_LIBRARIES})


MESSAGE(STATUS "--------------------------------------------")
MESSAGE(STATUS "Info :")
MESSAGE(STATUS "  Project Name = ${PROJECT_NAME}")
MESSAGE(STATUS "  Version =     ${PROJECT_VERSION}")
MESSAGE(STATUS "  CMAKE_VERSION =        ${CMAKE_VERSION}")
MESSAGE(STATUS "  CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "  CMAKE_BUILD_TYPE =     ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "  CMAKE_INSTALL_LIBDIR = ${CMAKE_INSTALL_LIBDIR}")
message(STATUS "  Boost_LIBRARIES =        ${Boost_LIBRARIES}")
message(STATUS "  OpenCV_VERSION =       ${OpenCV_VERSION}")