add_custom_target(
        linter
        COMMAND clang-tidy -p build/compile_commands.json src/**/src/*
        WORKING_DIRECTORY ..
)
