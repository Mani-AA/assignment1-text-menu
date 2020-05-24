compile:
	clang++ -std=c++17 -stdlib=libc++ -g menuDriver.cpp Text.cpp Menu.cpp -o menuDriver
run:
	./menuDriver
