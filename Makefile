ifeq ($(OS), Windows_NT)
	remove_command = del displaybmp.exe
else
	remove_command = rm -f displaybmp
endif

console_graphics:
	gcc console_graphics2.c displaybmp.c qdbmp.c -Ofast -o displaybmp
clean:
	$(remove_command)