# Note of EX 4

## gdb

** $ gdb --batch --ex run --ex bt --ex q --args ./{file} **
Run the program so that if it bombs, you get a baktrace.

- --batch: Run in batch mode. Exit after processing options.
- bt =  BackTrace: Dump a backtrace of the current calling stack.
- q = Quiet: Do not print the introductory and copyright messages. These messages are also suppressed in batch mode.
- --args: Arguments after excutable-file are passed to inferior.
- --ex, --eval-command=COMMAND: Execute a single GDB command. May be used multiple times and in conjunction with --command.

## Unsigned and Signed

- An unsighed variable type of int cannot hold negative number, and a signed int can hold nagative number.
- unsigned char is 0 to 256, while the range of a signed char is -127 to 127
