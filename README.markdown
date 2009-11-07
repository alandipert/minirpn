minirpn - 4 function RPN calculator REPL
========================================

This is a small calculator in C for RPN calculating at the command line.  Expressions are read from STDIN.

Usage
=================

Compile with 'make' and run 'rpn' to enter the REPL.  Supported operators:

*   __.__

    10 .

    Prints 10, the value at the top of the stack.

*   __+__

    10 2 1 + .

    Prints 13, the sum of 10, 2, and 1.

*   __-__

    100 50 - .

    Prints 50.

*   __/__

    12 4 / .

    Prints 3.

*   __*__

    3 3 * .

    Prints 9.

Note that you can 'peek' the stack anywhere in an expression, ie:

    10 2 + . 2 / .

    Prints "12" and then "6"
