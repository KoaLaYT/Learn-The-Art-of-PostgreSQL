add_library(lib database.cpp)

target_include_directories(lib PUBLIC ../include)

target_compile_features(lib PUBLIC cxx_std_17)
set_target_properties(lib PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(lib PRIVATE /usr/local/include)
target_link_libraries(lib PRIVATE ${PQXX} ${PQ})
target_link_libraries(lib PRIVATE fmt::fmt)