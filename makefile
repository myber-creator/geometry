all: bin/circle bin/test_circle
	./bin/test_circle

bin/test_circle: build/props.o build/print_scan.o build/main_test.o build/func_tests.o
	gcc -Wall -Werror build/main_test.o build/props.o build/print_scan.o build/func_tests.o -o bin/test_circle -lm

build/main_test.o: test/main.c
	gcc -Wall -Werror -I thirdparty -I src -c test/main.c -o build/main_test.o 

build/func_tests.o: test/func_tests.c
	gcc -Wall -Werror -I thirdparty -I src -c test/func_tests.c -o build/func_tests.o

bin/circle: build/main.o build/props.o build/print_scan.o
	gcc -Wall -Werror build/main.o build/props.o build/print_scan.o -o bin/circle -lm

build/props.o: src/props.c
	gcc -Wall -Werror -c src/props.c -o build/props.o 

build/print_scan.o: src/print_scan.c
	gcc -Wall -Werror -c src/print_scan.c -o build/print_scan.o 

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 
clean:
	rm -rf build/*.o bin/circle

.PHONY: all clean