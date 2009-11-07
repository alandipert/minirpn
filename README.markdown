rpn - 4 function CLI RPN calculator
========================================

This is a small calculator in C for RPN calculating at the command line.  Expressions are read from STDIN.  Compile with `make` and run `./rpn` to enter the REPL.

Usage
=================

*   __output__

        10 .

    Prints 10, the value at the top of the stack.

*   __addition__

        10 2 1 + .

    Prints 13, the sum of 10, 2, and 1.

*   __subtraction__

        100 50 - .

    Prints 50.

*   __division__

        12 4 / .

    Prints 3.

*   __multiplication__

        3 3 * .

    Prints 9.

Note that you can 'peek' the top of the stack anywhere in an expression, ie:

    10 2 + . 2 / .

    Prints "12" and then "6"
