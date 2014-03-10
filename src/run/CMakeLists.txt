file(GLOB_RECURSE run_src_files *.cpp)
add_executable(run.bin ${run_src_files})
set_target_properties(run.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DEFAULT_OUTPUT_DIR})
target_link_libraries(run.bin raycasting ${OpenCV_LIBS})
