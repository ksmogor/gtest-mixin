project(copy-resources)

set(RESOURCE_FILES test.txt)

# Copy generic resources
foreach(RESOURCE ${RESOURCE_FILES})
    add_custom_command(
            OUTPUT  ${PROJECT_BINARY_DIR}/${RESOURCE}
            DEPENDS ${PROJECT_SOURCE_DIR}/${RESOURCE}
            COMMAND ${CMAKE_COMMAND} -E copy
            ${PROJECT_SOURCE_DIR}/${RESOURCE}
            ${PROJECT_BINARY_DIR}/${RESOURCE}
    )

    # build a list of all the results
    list(APPEND COPIED_RESOURCES ${PROJECT_BINARY_DIR}/${RESOURCE})
endforeach()

# finally add the custom target that when invoked
# will cause the copy of resource files
add_custom_target(${PROJECT_NAME} ALL
        DEPENDS ${COPIED_RESOURCES}
)
