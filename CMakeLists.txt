cmake_minimum_required(VERSION 3.13.1)

project(c_logger)

# ------- Set Vars ------- #

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")
set(SOURCE_FILES src/main.c src/logger.c)

# ------- End Set Vars --- #

# ------- Executable ----- #
ADD_EXECUTABLE(c_logger_exec ${SOURCE_FILES})
ADD_LIBRARY(c_logger ${SOURCE_FILES})

# ------- End Executable - #

# ------- Finds ---------- #

# ------- End Finds ------ #

# ------- Inc & Link ---- #

# ------- End ----------- #
