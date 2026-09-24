# Myshell

Work in progress — not all planned features are implemented yet.

A Unix shell built from scratch in C.

## What it can do

* Runs any program on your system, like `ls`, `pwd`, `mkdir`, `git` (using `fork()` + `execvp()` + `waitpid()`)
* `cd` to change directories (plain `cd` goes to your home directory)
* Understands quotes, so `mkdir "two words"` creates one folder, not two
* Backslash escaping: `mkdir two\ words` does the same thing
* No fixed limit on how many arguments a command can have
* Command history:
   * stored in `~/.myshell_history`, so it works no matter which directory you launch or `cd` into
   * loaded automatically when the shell starts
   * saved back when you type `exit` or press `Ctrl+D`
   * `history` prints it, `history_clear` wipes it
   * empty lines are not saved
* `Ctrl+C` while a command is running stops only that command, the shell keeps going (each command runs in its own process group)
* Every `malloc`/`realloc` call is checked for failure before use, so a failed allocation fails safely instead of crashing with a segfault
* All memory is freed on exit, checked with AddressSanitizer: no leaks

## Build & run

gcc main.c -o main
./main

Or with warnings and AddressSanitizer (what I use while developing):

gcc -Wall -Wextra -g -fsanitize=address main.c -o main
./main


## Known issues

* `Ctrl+C` on an empty prompt closes the shell itself
* Arrow keys print raw escape codes instead of scrolling through history
* One input line is limited to about 255 characters

## Not done yet

* Pipes (`|`)
* Redirection (`>`, `<`)
* Background processes (`&`)
* Variable expansion (`$HOME`, `$?`), wildcards, aliases
* Tab completion

GL&HF.
