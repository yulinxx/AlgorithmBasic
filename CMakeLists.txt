
cmake_minimum_required(VERSION 3.0.0)

project(AlgorithmBasic VERSION 0.1.0)


message(STATUS "-----BEGIN------")


set(AlgorithmSrc    
    basicAlgorithm
)


foreach(SUB_DIR ${AlgorithmSrc})
    message(STATUS "---${SUB_DIR}")

    file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/${SUB_DIR}/*.cpp")
    message(STATUS "---all cpp: ${SRC}")
    set(index 0)

    foreach(CPP ${SRC})
        message(STATUS "---Create Exe: ${CPP}")

        MESSAGE(${CPP})
        STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${CPP})
        MESSAGE(" --- FILE_NAME"  ${FILE_NAME})

        # add_executable(${SUB_DIR}_${index}_${FILE_NAME} ${CPP})
        add_executable(${SUB_DIR}_${index} ${CPP})
        
        math(EXPR index "${index} + 1")

    endforeach(CPP)    

endforeach(SUB_DIR)


message(STATUS "-----END------")
