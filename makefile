
start: clean
	./SC
clean: test_lib
	-rm *.o
	-rm *.a
test_lib: test_lib.o mySimpleComputer.a
	-rm SC
	-gcc -o SC test_lib.o -L . -l mySimpleComputer
mySimpleComputer.a: mySimpleComputer.o
	-ar cr libmySimpleComputer.a mySimpleComputer.o 
test_lib.o:
	-gcc -c test_lib.c -o test_lib.o
mySimpleComputer.o:
	-gcc -c mySimpleComputer.c -o mySimpleComputer.o
