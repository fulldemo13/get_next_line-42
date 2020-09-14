# get_next_line

115/100

# Introduction

Write a function which returns a line read from a
file descriptor, without the newline.


# Mandatory part

External functions allowed: read, malloc, free

Description: Write a library that contains ft_printf, a function
that will mimic the real printf

Return values: 
1->A line has been read
0->EOF has been reached
-1->An error happened
```
-  Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.
- • Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used
as the buffer size for the read calls in your get_next_line. This value will be
modified by your evaluators and by moulinette.
- Your read must use the BUFFER_SIZE defined during compilation to read from
a file or from stdin.
