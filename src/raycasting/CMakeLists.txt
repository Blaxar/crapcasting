file(GLOB_RECURSE raycasting_src_files *.cpp)
add_library(raycasting SHARED ${raycasting_src_files})
set_target_properties(raycasting PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${DEFAULT_LINK_DIR})
target_link_libraries(raycasting ${OpenCV_LIBS})
