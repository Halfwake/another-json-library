token.o: token.c token.h
	gcc -c token.c

debug_token.o: debug_token.c debug_token.h
	gcc -c debug_token.c

test_token: test_token.c token.o debug_token.o
	gcc test_token.c token.o debug_token.o

