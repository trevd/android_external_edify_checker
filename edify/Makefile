lex.yy.o: lex.yy.c parser.h

parser.tab.c parser.h: parser.y
	bison --defines=parser.h parser.y

lex.yy.c: lexer.l
	flex lexer.l

clean:
	rm -f *.o *.yy.c *.tab.? parser.h
