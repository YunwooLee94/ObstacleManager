if (NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt\"")
endif()

file(READ "${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt" files_to_delete)

string(REGEX REPLACE "\n" ";" files_to_delete "${files_to_delete}")

foreach(file IN LISTS files_to_delete)
  message(STATUS "Deleting file: ${file}")
  if (EXISTS "${file}")
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E remove "${file}"
      OUTPUT_VARIABLE rm_out
      RESULT_VARIABLE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing file: ${file} - ${rm_out}")
    endif()
  endif()
endforeach()
