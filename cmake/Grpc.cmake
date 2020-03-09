set(GRPC_FOUND 1 CACHE INTERNAL "GRPC_FOUND")
set(GRPC_ROOT ${GEARS_ARCH} CACHE INTERNAL "GRPC_ROOT")
set(GRPC_INCLUDE_DIRS ${GRPC_ROOT}/include/grpc CACHE INTERNAL "GRPC_INCLUDE_DIRS")
set(GRPC_LIBRARY_DIRS ${GEARS_ARCH}/lib CACHE INTERNAL "GRPC_LIBRARY_DIRS")
file(GLOB LIBRARIES "${GRPC_LIBRARY_DIRS}/*.so")
set(GRPC_LIBRARIES ${LIBRARIES} CACHE INTERNAL "GRPC_LIBRARIES")
set(GRPC_CPP_PLUGIN_EXECUTABLE ${GRPC_ROOT}/bin/grpc_cpp_plugin CACHE INTERNAL "GRPC_CPP_PLUGIN_EXECUTABLE")

include_directories(${GRPC_INCLUDE_DIRS})
link_directories(${GRPC_LIBRARY_DIRS})