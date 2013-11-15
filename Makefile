all:
	$(MAKE) -C edify
	$(MAKE) edify_checker

edify_checker: edify/expr.o edify/lex.yy.o edify/parser.o builtins.o edify_checker.o
	gcc -Wall -O0 -oedify_checker $^

clean:
	rm -f *.o *.yy.c *.tab.? edify_checker edify_checker.exe
	$(MAKE) -C edify clean
