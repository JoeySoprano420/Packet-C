#include <string>
#include <vector>
#include <regex>
#include <unordered_map>

enum TokenType { PACKET, CAPSULE, IDENTIFIER, KEYWORD, SYMBOL, EOF_TOKEN };

struct Token {
    TokenType type;
    std::string value;
    int line, column;
};

class Lexer {
public:
    Lexer(const std::string &code) : source(code), pos(0), line(1), column(1) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        while (pos < source.size()) {
            char current = source[pos];
            if (std::isspace(current)) {
                if (current == '\n') line++, column = 1;
                pos++, column++;
            } else if (std::isalpha(current)) {
                tokens.push_back(identifier());
            } else if (current == '{' || current == '}') {
                tokens.push_back({SYMBOL, std::string(1, current), line, column});
                pos++, column++;
            } else {
                throw std::runtime_error("Unexpected character at line " + std::to_string(line));
            }
        }
        tokens.push_back({EOF_TOKEN, "", line, column});
        return tokens;
    }

private:
    std::string source;
    size_t pos;
    int line, column;

    Token identifier() {
        size_t start = pos;
        while (std::isalnum(source[pos]) || source[pos] == '_') pos++;
        std::string id = source.substr(start, pos - start);
        return {IDENTIFIER, id, line, column};
    }
};
