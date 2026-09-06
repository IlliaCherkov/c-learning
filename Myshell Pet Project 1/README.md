Myshell **This project is still under active development — not all planned features are implemented yet.*

A Unix shell built from scratch in C.

What it can do:

 Runs commands like ls, pwd, mkdir, etc.

 "cd" to change directories (plain cd goes to home directory)

 Understands quotes, so mkdir "two words" works as one argument, not two

 Keeps a history of commands, saved to log.txt when you  write command "exit"

 No fixed limit on how many arguments a command can have

Build & run:
bash

gcc main.c -o main

./main

OR

gcc -Wall -Wextra -g -fsanitize=address main.c -o main

./main

Not yet done:
Pipes (|),
Redirection (>, <),
Background processes (&),
Backslash escaping.

GL&HF.