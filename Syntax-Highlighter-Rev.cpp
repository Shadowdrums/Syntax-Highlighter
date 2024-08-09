#include <iostream>
#include <sstream>
#include <regex>
#include <string>

// ANSI escape codes for colors
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

// Function to colorize text
std::string colorize(const std::string& code, const std::string& color) {
    return color + code + RESET;
}

// Function to highlight code based on the language
std::string highlight_code(const std::string& code, const std::string& language) {
    std::string highlighted_code = code;

    if (language == "py") {
        // Keywords
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(def|print|return|if|else|elif|for|while|import|from|as|with|class|try|except|finally|lambda|pass|raise|yield|del|global|nonlocal|assert|break|continue|in|not|or|and|is|None|True|False)\\b"), GREEN + "$&" + RESET);
        // Built-in functions
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(len|type|range|list|dict|set|str|int|float|bool|input|open|dir|vars|help|print|id)\\b"), MAGENTA + "$&" + RESET);
        // Strings
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\".*?\"|'.*?'"), YELLOW + "$&" + RESET);
        // Comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("#.*"), BLUE + "$&" + RESET);
        // Function names
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\bdef\\s+(\\w+)"), MAGENTA + "def " + CYAN + "$1" + RESET);
    }
    else if (language == "js") {
        // Keywords
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(function|console|log|var|let|const|if|else|for|while|return|async|await|class|import|from|export|default|try|catch|finally|throw|switch|case|break|continue|do|new|this|super|extends|static|typeof|instanceof|void|delete|yield|typeof|instanceof|Promise|then|catch|finally)\\b"), GREEN + "$&" + RESET);
        // Built-in functions and objects
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(Math|Date|Array|String|Number|Object|JSON|parseInt|parseFloat|isNaN|isFinite|eval|setTimeout|setInterval|clearTimeout|clearInterval|RegExp)\\b"), MAGENTA + "$&" + RESET);
        // Strings
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\".*?\"|'.*?'|`.*?`"), YELLOW + "$&" + RESET);
        // Single-line comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("//.*"), BLUE + "$&" + RESET);
        // Multi-line comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("/\\*[^*]*\\*+(?:[^/*][^*]*\\*+)*/"), BLUE + "$&" + RESET);
        // Function names
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\bfunction\\s+(\\w+)"), MAGENTA + "function " + CYAN + "$1" + RESET);
    }
    else if (language == "cpp" || language == "c") {
        // Keywords
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(int|char|float|double|if|else|for|while|return|void|class|public|private|protected|virtual|override|const|constexpr|static|enum|struct|typedef|namespace|using|try|catch|throw|new|delete|this|operator|sizeof|template|typename|volatile|mutable|register|asm|auto|explicit|export|extern|friend|inline|long|restrict|short|signed|unsigned|goto|noexcept|static_assert|switch|case|default|union|break|continue|constexpr|dynamic_cast|explicit|inline|namespace|reinterpret_cast|static_cast|typedef|typename|union)\\b"), GREEN + "$&" + RESET);
        // Types and constants
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(bool|true|false|nullptr|int8_t|int16_t|int32_t|int64_t|uint8_t|uint16_t|uint32_t|uint64_t|size_t)\\b"), CYAN + "$&" + RESET);
        // Strings
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\".*?\"|'.*?'"), YELLOW + "$&" + RESET);
        // Single-line comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("//.*"), BLUE + "$&" + RESET);
        // Multi-line comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("/\\*[^*]*\\*+(?:[^/*][^*]*\\*+)*/"), BLUE + "$&" + RESET);
        // Function names
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b([\\w:]+)\\s*\\([^)]*\\)\\s*\\{"), CYAN + "$1" + RESET + " {");
    }
    else if (language == "java") {
        // Keywords
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(public|private|protected|class|interface|extends|implements|void|int|char|float|double|if|else|for|while|return|try|catch|throw|throws|new|static|final|enum|abstract|synchronized|volatile|transient|this|super|import|package|case|break|continue|do|instanceof|native|strictfp|switch|assert|default|goto|const|boolean|byte|short|long|super|transient|volatile|static|final)\\b"), GREEN + "$&" + RESET);
        // Types and constants
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(String|Integer|Boolean|Double|Character|Float|List|ArrayList|Map|HashMap|Set|HashSet|byte|short|int|long|float|double|char|boolean)\\b"), CYAN + "$&" + RESET);
        // Strings
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\".*?\"|'.*?'"), YELLOW + "$&" + RESET);
        // Single-line comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("//.*"), BLUE + "$&" + RESET);
        // Multi-line comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("/\\*[^*]*\\*+(?:[^/*][^*]*\\*+)*/"), BLUE + "$&" + RESET);
        // Function names
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b([\\w:]+)\\s*\\([^)]*\\)\\s*\\{"), CYAN + "$1" + RESET + " {");
    }
    else if (language == "html" || language == "xml") {
        // Tags
        highlighted_code = std::regex_replace(highlighted_code, std::regex("<[^>]+>"), GREEN + "$&" + RESET);
        // Attributes
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b\\w+(?==)"), CYAN + "$&" + RESET);
        // Strings
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\".*?\""), YELLOW + "$&" + RESET);
    }
    else if (language == "sh") {
        // Keywords
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\\b(echo|if|else|fi|for|while|do|done|case|esac|function|return|exit|break|continue|export|unset|readonly|trap|shift|getopts|select|alias|unalias|bg|fg|bind|builtin|caller|cd|command|compgen|complete|declare|dirs|disown|enable|eval|exec|exit|fc|fg|hash|help|jobs|kill|let|local|logout|mapfile|popd|pushd|read|readarray|source|suspend|test|times|type|ulimit|umask|unalias|wait)\\b"), GREEN + "$&" + RESET);
        // Strings
        highlighted_code = std::regex_replace(highlighted_code, std::regex("\".*?\"|'.*?'"), YELLOW + "$&" + RESET);
        // Comments
        highlighted_code = std::regex_replace(highlighted_code, std::regex("#.*"), BLUE + "$&" + RESET);
    }

    // Additional language handling can be added here

    return highlighted_code;
}

// Function to detect and highlight code blocks in the message
void detect_and_highlight_code_blocks(const std::string& message) {
    std::regex code_block_regex(R"(```(py|js|cpp|java|html|xml|c|go|php|ruby|sh|cs|r|swift|ts|kotlin)\s([\s\S]*?)```)");
    std::smatch match;
    std::string::const_iterator searchStart(message.cbegin());

    while (std::regex_search(searchStart, message.cend(), match, code_block_regex)) {
        std::string language = match[1].str();
        std::string code = match[2].str();

        std::string highlighted_code = highlight_code(code, language);

        std::cout << "Detected " << language << " code block:\n" << highlighted_code << "\n";

        searchStart = match.suffix().first;
    }
}

void display_instructions() {
    std::cout << "Instructions:\n";
    std::cout << "1. To start a code block, type three backticks followed by the language identifier (e.g., ```py for Python, ```js for JavaScript).\n";
    std::cout << "2. Enter your code. You can enter multiple lines by pressing Enter after each line.\n";
    std::cout << "3. To end the code block, type three backticks (```).\n";
    std::cout << "4. To submit your input, press Enter on an empty line after the closing backticks.\n";
    std::cout << "5. Supported languages: py, js, cpp, java, html, xml, c, go, php, ruby, sh, cs, r, swift, ts, kotlin.\n";
    std::cout << "Example:\n";
    std::cout << "Here is some Python code:\n";
    std::cout << "```py\n";
    std::cout << "def hello_world():\n";
    std::cout << "    print(\"Hello, world!\")\n";
    std::cout << "```\n";
    std::cout << "And some JavaScript:\n";
    std::cout << "```js\n";
    std::cout << "function helloWorld() {\n";
    std::cout << "    console.log(\"Hello, world!\");\n";
    std::cout << "}\n";
    std::cout << "```\n";
}

int main() {
    display_instructions();

    std::string message;
    std::cout << "Enter your message with code blocks:\n";

    // Read multiline input
    std::ostringstream input_stream;
    std::string line;
    bool in_code_block = false;
    while (std::getline(std::cin, line)) {
        if (line.find("```") != std::string::npos) {
            if (in_code_block) {
                // Closing code block
                input_stream << line << "\n";
                break;
            }
            else {
                // Opening code block
                in_code_block = true;
            }
        }
        input_stream << line << "\n";
    }
    message = input_stream.str();

    detect_and_highlight_code_blocks(message);

    return 0;
}
