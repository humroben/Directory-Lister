#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "File.h"

#include <string>
#include <vector>

class Directory {
public:
	Directory(std::string name);
	virtual ~Directory();

	void SetAttributes(std::string path);
	void Init(std::string path);

	void Print(std::string pad = "");

private:
	std::vector<Directory> dirs;
	std::vector<File> files;

	std::string name, mtime;
};

#endif
