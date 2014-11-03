##########################
# SetCUDALibTarget.cmake #
##########################

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/lib)

IF(WITH_CUDA)
  CUDA_ADD_LIBRARY(${targetname} STATIC ${sources} ${headers} ${templates} OPTIONS --generate-code arch=compute_20,code=sm_20 --generate-code arch=compute_30,code=sm_30)
ELSE()
  ADD_LIBRARY(${targetname} STATIC ${sources} ${headers} ${templates})
ENDIF()

SET_TARGET_PROPERTIES(${targetname} PROPERTIES DEBUG_OUTPUT_NAME "${targetname}_d")