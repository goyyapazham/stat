test: test.c
	gcc test.c -o test

clean:
	rm *~

run: test
	./test
