#include "Directory.h"

#include <iostream>

int main () {
	Directory dir("git");
	dir.SetAttributes("/home/humroben");
	dir.Init("/home/humroben/git");

	std::cout << "/home/humroben/git" << std::endl;
	dir.Print();

	return 0;
}
