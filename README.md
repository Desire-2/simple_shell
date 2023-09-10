## Simple Shell Project (0x16)
This is the README file for the Simple Shell project, a C-based UNIX command-line interpreter. This project is part of the ALX SE curriculum and is a group project completed by Desire Bikorimana and Uwamariya Assumpta. The project started on September 6, 2023, and must be completed by September 21, 2023.

## Project Overview
The Simple Shell project aims to create a basic UNIX command interpreter. The project involves writing a program that can read and execute simple command lines entered by the user. The key features of the Simple Shell include:

Displaying a prompt and waiting for the user to enter a command.
Executing commands and displaying the output.
Handling errors gracefully.
Implementing built-in commands such as exit and env.
Handling command lines with arguments.
Managing the PATH variable to locate executable files.
Implementing the setenv and unsetenv built-in commands.
Implementing the cd (change directory) built-in command.
Handling logical operators (&& and ||).
Handling aliases.
Handling variables replacement.
Handling comments.
Reading commands from a file.
Project Requirements
The code must adhere to the Betty coding style.
The shell should not have memory leaks.
No more than 5 functions per file.
All header files should be include guarded.
System calls should be used only when necessary.
A README.md file at the root of the project folder is mandatory.
An AUTHORS file at the root of the repository listing all contributors.
Compilation command: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh.

## How to Use the Simple Shell
To use the Simple Shell, follow these steps:

Clone the repository to your local machine.
Compile the source code using the provided compilation command.
Run the shell using ./hsh.
Enter commands and execute them.

shell
Copy code
$ ./hsh
($) /bin/ls
file1 file2 file3
($) exit
$

## Project Tasks
The project consists of several tasks, each building upon the previous one. Here's a brief overview of the tasks:

* Task 0: Betty would be proud
Ensure the code follows the Betty coding style.

* Task 1: Simple shell 0.1
Create a basic shell that can execute simple commands.

* Task 2: Simple shell 0.2
Extend the shell to handle command lines with arguments.

* Task 3: Simple shell 0.3
Implement PATH handling and prevent unnecessary forks.

* Task 4: Simple shell 0.4
Implement the exit built-in command.

* Task 5: Simple shell 1.0
Implement the env built-in command to display the current environment.

* Task 6: Simple shell 0.1.1
Write a custom getline function to read user input.

* Task 7: Simple shell 0.2.1
Remove the use of strtok in the shell.

* Task 8: Simple shell 0.4.1
Add support for arguments in the exit built-in command.

* Task 9: setenv, unsetenv
Implement the setenv and unsetenv built-in commands.

* Task 10: cd
Implement the cd built-in command for changing directories.

* Task 11: ;
Handle command separators (;).

* Task 12: && and ||
Handle logical operators (&& and ||).

* Task 13: alias
Implement the alias built-in command for defining and listing aliases.

* Task 14: Variables
Handle variable replacement, including $? and $$.

* Task 15: Comments
Handle comments (#) in command lines.

* Task 16: File as input
Allow the shell to read commands from a file.

