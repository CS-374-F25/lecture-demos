#include <stdio.h>

void bar() {
	printf("Bar!\n");
}

void foo() {
	bar();
	printf("Foo!\n");
	bar();
}

int main() {
	int x = 5;
	printf("Hello, World!\n");
	foo();
	x = 6;

	// In English, dynamic means "moving" / "changing". Static means
	// "fixed" / "unchanging".
	
	// In CS, very often dynamic means "at runtime". Static means
	// "before runtime".

	// Static analysis: Analyzing code itself. Compilers do this. Linters.
	// LSPs do it.
	//
	// Dynamic analysis: Analyzing the program while it runs. Debuggers.
	// Valgrind. GDB. IDE-builtin debuggers.
	//
	// GNU debugger (GDB) lets you run your program line by line.
	
	int i;
	for (i = 0; i < 10; ++i) {
		printf("Hello!%d\n", i);
	}
}
