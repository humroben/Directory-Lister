#ifndef FILE_H
#define FILE_H

#include <chrono>
#include <string>

class File {
public:
	File(std::string fname);
	virtual ~File();

	void SetAttributes(std::string path);

	void Print(std::string pad);

private:
	std::uintmax_t size;
	std::string name, mtime;
};

#endif
