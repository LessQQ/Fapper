/*
 *  Iberia.cpp
 *  Iberia
 *
 *  Created by Robb on 3/25/17.
 *  Copyright © 2017 Robb Long. All rights reserved.
 *
 */

#include "Iberia.hpp"

double Iberia::CreateDataStore(const char *path, const char *fileName)
{
	std::string strPath = path;
	std::string strFileName = fileName;
	std::string fqn = _ibHelp.MakeFullFileName(strPath, "/", strFileName);
	double result = CreateDS(fqn.c_str());
	return result;
}
double Iberia::LoadDataStore(const char *path, const char *fileName)
{
	std::string strPath = path;
	std::string strFileName = fileName;
	std::string fqn = _ibHelp.MakeFullFileName(strPath, "/", strFileName);
	double result = LoadDS(fqn.c_str());
	return result;
}
double Iberia::SaveDataStore(const char *path, const char *fileName)
{
	std::string strPath = path;
	std::string strFileName = fileName;
	std::string fqn = _ibHelp.MakeFullFileName(strPath, "/", strFileName);
	double result = SaveDS(fqn.c_str());
	return result;
}

bool Iberia::CreateDS(const char *fileName)
{
	std::string fn = fileName;
	_dataStore.SetFileName(fn);
	_dataStore.Clear();
	_dataStore.Save();
	return _ibIO.FileExist(fileName);
}

int Iberia::LoadDS(const char *fileName)
{
	if (!_ibIO.FileExist(fileName))
		return false;

	std::string fn = fileName;
	_dataStore.Load(fn);

	return true;
}
int Iberia::SaveDS(const char *fileName)
{
	std::string fn = fileName;
	_dataStore.Save(fn);
	return true;
}
bool Iberia::Save()
{
	_dataStore.Save(_fileName.c_str());
	return true;
}
int Iberia::Contains(const char *key)
{
	bool result = _dataStore.Contains(key);
	return result;
}
void Iberia::Add(const char *key, const char *value)
{
	std::string data = key;
	std::string node = value;
	_dataStore.Add(data, node);
}
void Iberia::Update(const char *key, const char *value)
{
	std::string data = key;
	std::string node = value;
	_dataStore.Update(data, node);
}
const char *Iberia::Get(const char *key)
{
	std::string data = key;
	std::string node = _dataStore.Get(data);
	return node.c_str();
}
void Iberia::Remove(const char *key)
{
	if (!Contains(key))
		return;
	std::string data = key;
	_dataStore.Remove(data);
}
void Iberia::LoadIDS(std::string fn)
{
	if(_ibIO.FileExist(fn.c_str()))
	{
		_dataStore.Load(fn);
	}
	else
	{
		std::cout << "unable to find '" << fn << "'" << std::endl;
	}
}

// Added on some fileName stuff
void Iberia::SetFileName(std::string fileName)
{
	//std::cout << "File Name: '" << fileName << "'" << std::endl;
	_fileName = fileName;
}
void Iberia::SetFileName(const char *fileName)
{
	std::string str(fileName);
	SetFileName(str);
}
const char *Iberia::GetFileName()
{
	return _fileName.c_str();
}
// *********** App stuff **********
bool Iberia::Contains(std::string key)
{
	bool result = Contains(key.c_str());
	return result;
}
void Iberia::Add(std::string key, std::string svalue)
{
	Add(key.c_str(), svalue.c_str());
}
void Iberia::Update(std::string key, std::string svalue)
{
	Update(key.c_str(), svalue.c_str());
}
std::string Iberia::Get(std::string key)
{
	std::string result = Get(key.c_str());
	return result;
}
void Iberia::Remove(std::string key)
{
	Remove(key.c_str());
}
std::vector<std::string> Iberia::ListData(std::string fileName, KVData kvd)
{
	std::vector<std::string> buffer;
	std::vector<std::string> data = _dataStore.ListDS(fileName);

	for (size_t i = 0; i < data.size(); i++)
	{
		std::string line = data[i];
		DataNode dn = _ibHelp.StringToDataNode(line);
		if (kvd == Key)
			buffer.push_back(dn._Key);
		else if (kvd == Value)
			buffer.push_back(dn._Value);
		else
			buffer.push_back(line);
	}
	return buffer;
}








