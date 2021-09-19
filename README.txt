Student: Sean Dela Pena 
Professor: Mark Hauschild
Assignment: Project 0 - CS 4280
	The purpose of this assignment is to practice with standards and header files, 
	practice with trees, traversals, command line arguments, and file IO.
	This program creates a binary tree base on the first alphanumerical character,
	then prints by the tree different traversals.
Date: 9/19/2021

USAGE: make		(makefile to compile, creates a P0 executable)
	./P0 [somefile] [< somefile] [keyboard input]
	make clean	(removes the exec and three traversal files)

Three example invocations:
	./P0 somefile.txt [enter]

	./P0 < somefile.txt [enter]

	./P0 [enter]
	this 
	is an 
	example
	of keyboard
	input
	[ctrl + d]

Notes:
	This program was not tested with special characters as input. As explained in class the inputs
	will only be alphanumerical. 

	The program is tested only with the three proper invocations presented above and in the project
	prompt. If the program is not used properly there won't be any perror message and the program
	might not run properly. 

	Third party sources will be found cited at the top of "tree.cpp" file. The code taken from those 
	sources are revised to fit the project description. 

	Levels are represented by tabs "\t", root (no tab), level 1 (1 tab), level 2 (2 tabs) and so on.
	It should look like a tree in a horizontal orientation. I commented out the displaying of level
	number because it looks messy and without it the print looks more of a tree.
	