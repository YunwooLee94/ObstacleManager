cmake_minimum_required(VERSION 3.15.0)
project(obstacle_manager)
set(PACKAGE_EXPORT_NAME ObstacleManager)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17")
set(CMAKE_BUILD_TYPE Release)
set(SOURCE_FOLDERS "obstacle_manager" "object_state")

# Uncomment the below if you want to other directory (default: /usr/local)
# set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)
find_package(PCL 1.13 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
find_package(BernsteinPolynomialUtil REQUIRED)

file(
  GLOB PROJECT_SUBFOLDERS
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  ${SOURCE_FOLDERS})
set(LIBRARY_SOURCES "")

foreach(SUBFOLDER ${PROJECT_SUBFOLDERS})
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBFOLDER})
    file(GLOB SUBFOLDER_SOURCES
         "${CMAKE_CURRENT_SOURCE_DIR}/${SUBFOLDER}/*.cpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/${SUBFOLDER}/*.hpp")
    list(APPEND LIBRARY_SOURCES ${SUBFOLDER_SOURCES})
  endif()
endforeach()

add_library(${PROJECT_NAME} SHARED ${LIBRARY_SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES} bernstein_polynomial_util)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PACKAGE_EXPORT_NAME}
  LIBRARY DESTINATION lib
  INCLUDES
  DESTINATION include)

foreach(SUBFOLDER ${PROJECT_SUBFOLDERS})
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBFOLDER})
    file(GLOB SUBFOLDER_HEADERS "${SUBFOLDER}/*.hpp")
    install(FILES ${SUBFOLDER_HEADERS} DESTINATION include/${SUBFOLDER})
  endif()
endforeach()

export(TARGETS ${PROJECT_NAME}
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_EXPORT_NAME}Config.cmake")

install(
  EXPORT ${PACKAGE_EXPORT_NAME}
  FILE ${PACKAGE_EXPORT_NAME}Config.cmake
  DESTINATION ${CMAKE_INSTALL_PREFIX})

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake" IMMEDIATE @ONLY)

add_custom_target(
  uninstall COMMAND ${CMAKE_COMMAND} -P
                    ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
