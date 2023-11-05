
add_subdirectory(external/cmakelibs/glfw)
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE GLAD_SOURCES external/shared/glad/*.c)
add_executable(${PROJECT_NAME} ${SOURCES} ${GLAD_SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        include/
        external/shared/glad/include
        glfw
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        glfw
)