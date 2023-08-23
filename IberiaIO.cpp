//
//  IberiaIO.cpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#include "IberiaIO.hpp"

bool IberiaIO::FileExist(const char *fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    return inFile.good();
}
bool Exists(std::string fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    return inFile.good();
}
int IberiaIO::CountLines(char *filename)
{
    int count = 0;
    string buffer;
    ifstream fin(filename);
    while (std::getline(fin, buffer))
        ++count;
    fin.close();
    
    return count;
}

int IberiaIO::NextLineNumber(char *filename)
{
    int c = CountLines(filename);
    c++;
    return c;
}

void IberiaIO::WriteLine(char *filename, char *str)
{
    ofstream fout(filename, ios::app);
    fout << str << endl;
    fout.close();
}

string IberiaIO::ReadFile(char *fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    
    stringstream strStream;
    strStream << inFile.rdbuf();
    string str = strStream.str();
    return str;
}

string IberiaIO::ReadFile(string fileName)
{
    IberiaMisc ibm;
    char *tstr = ibm.StringToChar(fileName);
    string result = ReadFile(tstr);
    return result;
}

double IberiaIO::WriteFile(char *filename, char *str)
{
    ofstream fout(filename);
    fout.write(str, sizeof(str));
    fout.close();
    
    return 0;
}

void IberiaIO::WriteData(std::vector<std::string> data, std::string fileName)
{
    ofstream fout(fileName.c_str(), std::ios::trunc);
    for (size_t i = 0; i < data.size(); i++)
    {
        std::string line = data[i];
        fout << line << std::endl;
    }
    fout.close();
}

std::vector<std::string> IberiaIO::ReadData(std::string fileName)
{
    //std::cout << "reading data" << std::endl;
    std::vector<std::string> result;
    //std::cout << "filename : '" << fileName << "'" << std::endl;
    ifstream inFile(fileName);
    std::string buffer;
    
    while (std::getline(inFile, buffer))
    {
        result.push_back(buffer);
    }
    //std::cout << "closing file" << std::endl;
    //std::cout << "results : '" << result << "'" << std::endl;
    inFile.close();
    return result;
}

void IberiaIO::IndexLine(char *line, char *filename)
{
    string buffer;
    string newline;
    IberiaMisc ibm;
    char *tok;
    int idx = CountLines(filename);
    idx += 1;
    tok = ibm.StringToChar("|");
    IberiaMisc im;
    string index = im.IntToString(idx);
    newline.append(index);
    newline.append(tok);
    newline.append(line);
    WriteLine(filename, strdup(newline.c_str()));
}

void IberiaIO::FileDelete(const char * fileName)
{
	remove(fileName);
}

void IberiaIO::MakeFolder(std::string folderName)
{
	#if __APPLE__
	mkdir(folderName.c_str(), 0777);
	#elif __linux__
	mkdir(folderName.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	#elif _WIN32
	//CreateDirectory(folderName.c_str(), NULL);
    _mkdir(folderName.c_str());
	#endif
}

std::string IberiaIO::GetFolderName()
{
    char buf[FILENAME_MAX];
#if __APPLE__
    char* succ = getcwd(buf, FILENAME_MAX);
#endif
    char* succ = getcwd(buf, FILENAME_MAX);

    if( succ ) 
        return std::string(succ);
    else
        return std::string("error"); 
}
char* IberiaIO::getCurrentDir(void)
{
    char buf[FILENAME_MAX];
    char* succ = getcwd(buf, FILENAME_MAX);
    return succ;
}

/*
char* IberiaIO::getCurrentDir(void)
{
    char *currWorkDir, *token;
    char buffer[PATH_MAX + 1];
    char *directory;
    size_t length;

    currWorkDir = getcwd(buffer, PATH_MAX + 1 );
    token = strrchr(currWorkDir, '/');

    length = strlen(token);
    //directory = malloc(length);
    std::string folderName;
    memcpy(folderName, token+1, length);

    return directory;
}
*/
