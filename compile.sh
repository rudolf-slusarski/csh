#!/bin/bash
if [ -f "csh" ]; then
    rm csh
fi
gcc -Wall -Wextra -Werror -pedantic *.c -o csh
