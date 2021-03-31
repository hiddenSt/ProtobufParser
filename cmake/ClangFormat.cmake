find_program(CLANG_FORMAT_TOOL
        NAMES
        clang-format
        clang-format-9.0
        clang-format-8.0
        clang-format-7.0)

function(add_clang_format_target NAME CWD)
    add_custom_target(${NAME}
            COMMAND ${CLANG_FORMAT_TOOL} --style=file -i ${ARGN}
            WORKING_DIRECTORY ${CWD}
            COMMENT "Applying clang-format (cwd = ${CWD})")
endfunction()