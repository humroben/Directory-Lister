#include "Directory.h"

#include <sstream>
#include <iomanip>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

Directory::Directory(string name) {
	this->name = move(name);
}

Directory::~Directory() { }

void Directory::SetAttributes(string path) {
	auto ftime = fs::last_write_time(path + "/" + name);
	time_t mtime = decltype(ftime)::clock::to_time_t(ftime);

	stringstream ss;
	ss << put_time(localtime(&mtime), "%d/%m/%y %OH:%OM:%OS");
	this->mtime = ss.str();
}

void Directory::Init(string path){
	for (auto &p : fs::directory_iterator(path)) {
		if (fs::is_directory(p)) {
			Directory d(fs::path(p).filename());
			d.SetAttributes(path);

			string _path = fs::path(p);
			d.Init(_path);

			dirs.push_back(d);
		} else if (fs::is_regular_file(p)) {
			File f(fs::path(p).filename());
			f.SetAttributes(path);

			files.push_back(f);
		}
	}
}

void Directory::Print (string pad) {
	cout << pad << " \\_ " << name << " -- Mtime: " << mtime << endl;
	pad += "  ";
	for (vector<Directory>::iterator iter = dirs.begin(); iter < dirs.end(); iter++) {
		cout << " |";
		(*iter).Print(pad);
	}
	for (vector<File>::iterator iter = files.begin(); iter < files.end(); iter++) {
		cout << " |";
		(*iter).Print(pad);
	}
}
