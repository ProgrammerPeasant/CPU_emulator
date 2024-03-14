add_executable(Main main.cpp
        ../compiler/lexeme.cpp
        ../compiler/lexeme.h
        ../compiler/parser.cpp
        ../compiler/parser.h
)

target_include_directories(Main PRIVATE
        "${PROJECT_SOURCE_DIR}/lib/StackLib"
)

target_link_libraries(Main PRIVATE StackLib)