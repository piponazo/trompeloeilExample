add_library(myLib
    include/lib/Order.h
    include/lib/Store.h

    src/Order.cpp
)

target_include_directories(myLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include>
)

