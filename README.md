# Welcome to LewLang!

LewLang is a custom-made **REPL** interpreter coded in **C++**. REPL (read–eval–print loop) is a simple, interactive computer programming language that takes single user inputs, evaluates them, and returns the result to the user.

# Compiling

### Linux/MacOS

    git clone https://github.com/wkdwilliams/LewLang.git
    cd LewLang/
    cmake . && make

A compiled binary will be created with the name **LewLang**. Simply run `./LewLang` to run the interactive interpreter, or ./LewLang samples/tests.lew. to run a lew script.

# Documentation

To output text to the console, you use print;
```python
print "Hello World";
```

Functions can be created like so;
```swift
function bodmas(x: int, y: int): int
{
    return 4*(x+y);
}

print bodmas(5, 5); // Outputs 40
```
![enter image description here](https://github.com/wkdwilliams/LewLang/blob/master/lewlang.gif?raw=true)