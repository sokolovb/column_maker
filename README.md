### This util gets any text and transforms it into columns

Usage: 
- compile: <code>gcc columns.c -o columns</code>
- run: <code>./columns *%some_options_here%*</code>

|option       |description                                                                                 |
|-------------|--------------------------------------------------------------------------------------------|
|-c="int"     |*The number of columns (required)*                                                          |
|-b="int"     |*Begin from the symbol with number "b"*                                                     |
|-e="int"     |*End with the symbol with number "e"*                                                       |
|-r           |*Allow to cut and transfer to the next line part of words to fit them to columns precisely* |
|"input.txt"  |*Input file (if not stated, standart input to the newline symbol will take place)*          |
|"output.txt" |*Output file (if not stated, standart output will take place)*                              |
