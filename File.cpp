#include "File.h"

#include <sstream>
#include <iomanip>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

File::File(string fname) : size(0) {
	name = move(fname);
}

File::~File() { }

void File::SetAttributes(string path) {
	auto ftime = fs::last_write_time(path + "/" + name);
	time_t mtime = decltype(ftime)::clock::to_time_t(ftime);

	stringstream ss;
	ss << put_time(localtime(&mtime), "%d/%m/%y %OH:%OM:%OS");
	this->mtime = ss.str();

	size = fs::file_size(path + "/" + name);
}

void File::Print (string pad) {
	cout << pad << " \\_ " << name << " -- Mtime: " << mtime << endl;
}
