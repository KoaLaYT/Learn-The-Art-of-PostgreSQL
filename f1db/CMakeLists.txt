add_executable(f1db main.cpp)

target_compile_features(f1db PUBLIC cxx_std_17)
set_target_properties(f1db PROPERTIES CXX_EXTENSIONS OFF)

target_link_libraries(f1db PRIVATE fmt::fmt)
target_link_libraries(f1db PRIVATE lib)