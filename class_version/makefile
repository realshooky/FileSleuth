output: main.o ExtensionClass.o
	clang++ -o FileSleuth.exe main.o ExtensionClass.o
main.o: main.cpp
	clang++ -c -std=c++11 main.cpp
ExtensionClass.o: ExtensionClass.cpp
	clang++ -c -std=c++11 ExtensionClass.cpp
debug:
	clang++ -g -o FileSleuth.exe *.cpp
clean:
	rm *.o
