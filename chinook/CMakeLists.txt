add_executable(chinook main.cpp)

target_compile_features(chinook PUBLIC cxx_std_17)
set_target_properties(chinook PROPERTIES CXX_EXTENSIONS OFF)

target_link_libraries(chinook PRIVATE fmt::fmt)
target_link_libraries(chinook PRIVATE lib)