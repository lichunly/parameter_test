cmake_minimum_required(VERSION 2.8)
project(parameter_test)

include(${CMAKE_SOURCE_DIR}/cmake/ProtoCompiler.cmake)

# Compile proto files

# Compile proto files
protobuf_compile_directory_flat(${CMAKE_CURRENT_SOURCE_DIR}/proto "proto" PROTO_SRCS)
set(GRPC_PROTOS "decision/decision_service.proto"
        "routing/routing_service.proto"
        "simulation/service_nodejs_to_cpp.proto"
        "simulation/update_pointcloud.proto"
        "simulation/update_sim_world.proto"
        "hmi/hmi_grpc_api.proto"
        "calibration/calibration_grpc_api.proto"
        "hmi/launcher_grpc_api.proto"
        "hmi-workers/openapi_client_fm_grpc.proto"
        "hmi-workers/openapi_server_mobile_grpc.proto"
        "hmi-workers/openapi_common_service.proto"
        "hmi-workers/openapi_onboard.proto"
        "hmi-state/state_grpc_api.proto"
        "inspector/inspector_service.proto"
        "calibrator/calibrator_service.proto"
        "collection/collection_service.proto"
        "closeloop/closeloop_service.proto"
        "collector/statecollector_service.proto"
        "collector/data_worker_service.proto"
        "collector/taskid_service.proto"
    )
    
protobuf_compile_directory_flat_with_grpc(${CMAKE_CURRENT_SOURCE_DIR}/neolix "${GRPC_PROTOS}" "proto" MODULE_PROTO_SRCS)
# protobuf_compile_directory_flat(${CMAKE_CURRENT_SOURCE_DIR}/src/neolix "proto" MODULE_PROTO_SRCS)
# add_library(cyber_proto SHARED ${PROTO_SRCS})
# target_link_libraries(cyber_proto protobuf pthread)


# protobuf_compile_directory_flat(${CMAKE_CURRENT_SOURCE_DIR}/proto "proto" PROTO_SRCS)
add_library(parameter_test_proto SHARED ${PROTO_SRCS} ${MODULE_PROTO_SRCS})
target_link_libraries(parameter_test_proto protobuf pthread)

aux_source_directory(${PROJECT_SOURCE_DIR} EXAMPLE_SRCS)

add_library(${PROJECT_NAME} SHARED ${EXAMPLE_SRCS})
target_link_libraries(${PROJECT_NAME} 
    cyber
    parameter_test_proto
    )

# install(DIRECTORY
#             ${CMAKE_CURRENT_SOURCE_DIR}/data_center
#             ${CMAKE_CURRENT_SOURCE_DIR}/checker
#             ${CMAKE_CURRENT_SOURCE_DIR}/common
#         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/guardian/
#         FILES_MATCHING PATTERN "*.h")

install(TARGETS ${PROJECT_NAME} parameter_test_proto
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)