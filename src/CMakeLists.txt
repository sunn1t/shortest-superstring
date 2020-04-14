add_library(lib "")

target_sources(
    lib
    PRIVATE
        algorithms.cpp
        common.cpp
        graph.cpp
        tcp.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/algorithms.h
        ${CMAKE_CURRENT_LIST_DIR}/common.h
        ${CMAKE_CURRENT_LIST_DIR}/graph.h
        ${CMAKE_CURRENT_LIST_DIR}/tcp.h
    )

target_include_directories(
    lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
