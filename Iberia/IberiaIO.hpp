//
//  IberiaIO.hpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#ifndef IberiaIO_hpp
#define IberiaIO_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <sys/stat.h>

#if __APPLE__
#include <stdlib.h>
#include <unistd.h>
#elif __linux__
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#elif _WIN32
#include <Windows.h>
#include <direct.h>
#endif

#include "IberiaMisc.hpp"

using namespace std;

class IberiaIO
{
public:
    bool FileExist(const char *fileName);
    bool Exists(std::string fileName);
    int CountLines(char *filename);
    int NextLineNumber(char *filename);
    void WriteLine(char *filename, char *str);
    string ReadFile(char *fileName);
    string ReadFile(string fileName);
    double WriteFile(char *filename, char *str);
    void IndexLine(char *line, char *filename);
	void FileDelete(const char *fileName);

	void MakeFolder(std::string folderName);
    char* getCurrentDir(void);
    std::string GetFolderName();
    
    void WriteData(std::vector<std::string> data, std::string fileName);
    std::vector<std::string> ReadData(std::string fileName);
};

#endif /* IberiaIO_hpp */
