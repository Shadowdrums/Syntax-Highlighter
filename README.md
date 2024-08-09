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

(```py)
```py
def hello_world():
    "print("Hello, world!")
```
(```)

you open with three back ticks followed by the file extension for the coding language, then write your code, finally close it with 3 back ticks, new line for each step.

### Output: The tool will display the syntax-highlighted code in the terminal.

# MIT License

Copyright (c) 2024 Shadowdrums

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


## Contributing
Contributions are welcome! Feel free to fork the repository and submit a pull request with improvements or new features.
