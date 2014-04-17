cmake_minimum_required(VERSION 2.8)
project(NumericBindings)

set(HEADER_INST_DIR "${CMAKE_INSTALL_PREFIX}/include")

install(DIRECTORY "${NumericBindings}"
        DESTINATION "${HEADER_INST_DIR}"
        FILES_MATCHING PATTERN "*.h*"
        PATTERN "Jamroot" EXCLUDE
        PATTERN "CMake*" EXCLUDE
        PATTERN "libs" EXCLUDE
        PATTERN ".git" EXCLUDE
)

