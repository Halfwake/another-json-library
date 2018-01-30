json.o: json.c json.h
	gcc -g -c json.c

token.o: token.c token.h
	gcc -g -c token.c

debug_token.o: debug_token.c debug_token.h
	gcc -g -c debug_token.c

test_token: test_token.c token.o debug_token.o
	gcc -g test_token.c token.o debug_token.o

