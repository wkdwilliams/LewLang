# Welcome to LewLang!

LewLang is a custom-made **REPL** interpreter coded in **C++**. REPL (read–eval–print loop) is a simple, interactive computer programming language that takes single user inputs, evaluates them, and returns the result to the user.

# Compiling

### Linux/MacOS

    git clone https://github.com/wkdwilliams/LewLang.git
    cd LewLang/
    cmake . && make

A compiled binary will be created. Simply run `./LewLang` to run the interactive interpreter, or `./LewLang samples/tests.lew` to run a lew script.

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

<hr />
<p align="center">
  <img src="https://github.com/wkdwilliams/LewLang/blob/master/lewlang.gif?raw=true">
</p>

# Extended Backus–Naur Form

```
 ‹program›           = { ‹statement› }
 
 ‹block›             = "{" { ‹statement› } "}"
 
 ‹statement›         = ‹variable-decl› ";"
                     | ‹assignment› ";"
                     | ‹print-statement› ";"
                     | ‹if-statement›
                     | ‹while-statement›
                     | ‹return-statement› ";"
                     | ‹function-decl›
                     | ‹block›
 
 ‹function-decl›     = "def" ‹identifier› "(" [‹formal-params›] ")" ":" ‹type› ‹block›
 
 ‹formal-params›     = ‹formal-param› { "," ‹formal-param› }
 
 ‹formal-param›      = ‹identifier› ":" ‹type›
 
 ‹while-statement›   = "while" "(" ‹expression› ")" ‹block›
 
 ‹if-statement›      = "if" "(" ‹expression› ")" ‹block› ["else" ‹block›]
 
 ‹return-statement›  = "return" ‹expression›
 
 ‹print-statement›   = "print" ‹expression›
 
 ‹variable-decl›     = "var" ‹identifier› ":" ‹type› "=" ‹expression›
 
 ‹assignment›        = "set" ‹identifier› "=" ‹expression›
 
 ‹expression›        = ‹simple-expression› { ‹relational-op› ‹simple-expression› }
 
 ‹simple-expression› = ‹term› { ‹additive-op› ‹term› }
 
 ‹term›              = ‹factor› { ‹multiplicative-op› ‹factor› }
 
 ‹factor›            = ‹literal›
                     | ‹identifier›
                     | ‹function-call›
                     | ‹sub-expression›
                     | ‹unary›
 
 ‹unary›             = ( "+" | "-" | "not" ) { ‹expression› }
 
 ‹sub-expression›    = "(" ‹expression› ")"
 
 ‹function-call›     = ‹identifier› "(" [‹actual-params›] ")"
 
 ‹actual-params›     = ‹expression› { "," ‹expression› }
 
 ‹relational-op›     = "<" | ">" | "==" | "!=" | "<=" | ">="
 
 ‹additive-op›       = "+" | "-" | "or"
 
 ‹multiplicative-op› = "*" | "/" | "and"
 
 ‹identifier›        = ( "_" | ‹letter› ) { "_" | ‹letter› | ‹digit› }
 
 ‹literal›           = ‹int-literal | integer-literal›
                     | ‹real-literal›
                     | ‹bool-literal | boolean-literal›
                     | ‹string-literal | text-literal›
 
 ‹int-literal›       = ‹digit› { ‹digit› }
 
 ‹real-literal›      = ‹digit› { ‹digit› } "." { ‹digit› }
                     | "." ‹digit› { ‹digit› }
 
 ‹bool-literal›      = "true" | "false"
 
 ‹string-literal›    = "“" { ‹printable› } "”"
 
 ‹printable›         = ‹digit› | ‹letter› | " " | "!" | """ | "#" | "$" | "%" | "&"
                     | "'" | "(" | ")" | "*" | "+" | "," | "-" | "." | "/" | ":" | ";"
                     | "<" | "=" | ">" | "?" | "@" | "[" | "\" | "]" | "^" | "_" | "`"
                     | "{" | "|" | "}" | "~"
 
 ‹letter›            = "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K"
                     | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V"
                     | "W" | "X" | "Y" | "Z" | "a" | "b" | "c" | "d" | "e" | "f" | "g"
                     | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r"
                     | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z"
 
 ‹digit›             = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
```