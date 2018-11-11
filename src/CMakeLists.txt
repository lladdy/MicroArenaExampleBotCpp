# Example Bot source files
file(GLOB SOURCES_EXAMPLEBOT "*.cpp" "*.h")

# Include directories
include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/s2client-api/include
    ${PROJECT_BINARY_DIR}/s2client-api/generated
)

# Create the executable.
add_executable(MicroArenaExampleBotCpp ${SOURCES_EXAMPLEBOT})
target_link_libraries(MicroArenaExampleBotCpp
    sc2api sc2lib sc2utils
)