add_executable(Main main.cpp
        ../compiler/lexeme.cpp
        ../compiler/lexeme.h
        ../parser/include/arch.h
        ../parser/include/parser.h
        ../parser/include/utils.h
        ../parser/include/command.h
        ../parser/src/arch.cpp
        ../parser/include/arch.h
        ../parser/src/command.cpp
        ../parser/src/parser.cpp
        ../parser/src/utils.cpp
)


target_include_directories(Main PRIVATE
        "${PROJECT_SOURCE_DIR}/lib/StackLib"
)


target_link_libraries(Main PRIVATE StackLib)