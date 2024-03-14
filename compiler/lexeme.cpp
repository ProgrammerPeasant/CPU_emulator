#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include "lexeme.h"

std::vector<std::string> collectLexemes(const std::string& filePath) {
    std::vector<std::string> lexemes;
    std::ifstream file(filePath);

    if (!file) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return lexemes;
    }

    std::string lexeme;
    char c;

    while (file.get(c)) {
        if (isalnum(c)) {
            lexeme += c;
        } else {
            if (!lexeme.empty()) {
                lexemes.push_back(lexeme);
                lexeme.clear();
            }

            if (ispunct(c) && c != '\'') {
                std::string punctuation(1, c);
                lexemes.push_back(punctuation);
            } else if (c == '\n') {
                lexemes.emplace_back("\n");
            }
        }
    }

    if (!lexeme.empty()) {
        lexemes.push_back(lexeme);
    }

    file.close();
    return lexemes;
}