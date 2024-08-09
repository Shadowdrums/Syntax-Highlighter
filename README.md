# Syntax-Highlighter
simple Code Syntax Highlighter in C++

# Code Syntax Highlighter

This project is a simple command-line tool written in C++ that allows users to input code snippets in various programming languages and outputs the syntax-highlighted version of the code. The highlighting is based on ANSI escape codes, making it suitable for terminal/console output.

## Features

- **Multi-language support**: The tool currently supports the following programming languages:
  - Python (`py`)
  - JavaScript (`js`)
  - C++ (`cpp`)
  - Java (`java`)
  - HTML/XML (`html`, `xml`)
  - C (`c`)
  - Shell scripts (`sh`)
  - Additional languages can be easily added.

- **Syntax highlighting**: The tool highlights:
  - Keywords
  - Built-in functions and objects
  - Strings
  - Comments
  - Function names

## How It Works

1. The user inputs code wrapped in triple backticks followed by the language identifier (e.g., \```py``` for Python).
2. The tool detects the code block, identifies the language, and applies the appropriate syntax highlighting using ANSI escape codes.
3. The highlighted code is then displayed in the terminal.

## Usage

1. **Compile the Program**:  
   Use a C++ compiler to compile the program. For example, using `g++`:
   ```sh
   g++ -o highlighter highlighter.cpp
   ```
## Run the Program:
```bash
./highlighter
```

### Input Your Code:

Start a code block with three backticks followed by the language identifier.
Enter your code. You can enter multiple lines by pressing Enter after each line.
End the code block with three backticks and press Enter on an empty line to submit your input.

### Example:

(```py
def hello_world():
    "print("Hello, world!")
```)
Output: The tool will display the syntax-highlighted code in the terminal.
