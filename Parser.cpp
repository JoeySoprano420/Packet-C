struct Node {
    std::string name;
    std::vector<Node> children;
};

class Parser {
public:
    Parser(const std::vector<Token> &tokens) : tokens(tokens), current(0) {}

    Node parse() {
        Node root = parsePacket();
        return root;
    }

private:
    std::vector<Token> tokens;
    size_t current;

    Node parsePacket() {
        expect(TokenType::PACKET);
        std::string name = expect(TokenType::IDENTIFIER).value;
        expect(TokenType::SYMBOL, "{");
        Node packet = {name};
        while (peek().type != SYMBOL || peek().value != "}") {
            packet.children.push_back(parseCapsule());
        }
        expect(TokenType::SYMBOL, "}");
        return packet;
    }

    Node parseCapsule() {
        expect(TokenType::CAPSULE);
        std::string name = expect(TokenType::IDENTIFIER).value;
        expect(TokenType::SYMBOL, "{");
        Node capsule = {name};
        // Add parsing for statements here
        expect(TokenType::SYMBOL, "}");
        return capsule;
    }

    Token expect(TokenType type, const std::string &value = "") {
        if (current >= tokens.size())
            throw std::runtime_error("Unexpected end of input.");
        Token token = tokens[current++];
        if (token.type != type || (!value.empty() && token.value != value))
            throw std::runtime_error("Expected " + value + " at line " + std::to_string(token.line));
        return token;
    }

    Token peek() { return tokens[current]; }
};
