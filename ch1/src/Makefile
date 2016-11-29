# 链接器: ld
hello: hello.o
	gcc hello.o -o hello

# 汇编器: as
hello.o: hello.s
	gcc -c hello.s -o hello.o

# 编译器: cc0
hello.s: hello.i
	gcc -S hello.i -o hello.s

# 预处理器: cpp
hello.i: hello.c
	gcc -E hello.c -o hello.i

.PHONY: .clean
clean:
	rm -rf hello hello.o

run:
	./hello
