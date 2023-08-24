//
//  IberiaDataStore.cpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#include "IberiaDataStore.hpp"

bool IberiaDataStore::Contains(std::string key)
{
    if (_dataMap.find(key) == _dataMap.end())
        return false;
    else
        return true;
}

void IberiaDataStore::Add(std::string key, std::string value)
{
    if (!Contains(key))
        _dataMap.insert(std::map<std::string,std::string>::value_type(key,value));
    else
        Update(key, value);
}

std::string IberiaDataStore::Get(std::string key)
{
    std::string result;
    std::map<std::string, std::string>::iterator it = _dataMap.find(key);
    if (it != _dataMap.end())
        result = it->second;
    else
        result = "Error: key '" + key + "' not found.";
    return result;
}

void IberiaDataStore::Update(std::string key, std::string value)
{
    std::map<std::string, std::string>::iterator it = _dataMap.find(key);
    if (it != _dataMap.end())
        it->second = value;
}

void IberiaDataStore::Remove(std::string key)
{
    if (!Contains(key))
        return;
    std::map<std::string, std::string>::iterator it = _dataMap.find(key);
    _dataMap.erase(it);
}

void IberiaDataStore::Save()
{
    Save(_dmFileName);
}

void IberiaDataStore::Save(std::string fileName)
{
    std::map<std::string, std::string>::iterator iter;
    std::vector<std::string> buffer;
    
    for (iter = _dataMap.begin(); iter != _dataMap.end(); ++iter)
    {
        DataNode dn;
        dn._Key = iter->first;
        dn._Value = iter->second;
        std::string line = ibHelp.DataNodeToString(dn);
        buffer.push_back(line);
    }
    ibIO.WriteData(buffer, fileName);
}

std::vector<std::string> IberiaDataStore::ListDS(std::string fileName)
{
    std::map<std::string, std::string>::iterator iter;
    std::vector<std::string> buffer;
    
    for (iter = _dataMap.begin(); iter != _dataMap.end(); ++iter)
    {
        DataNode dn;
        dn._Key = iter->first;
        dn._Value = iter->second;
        std::string line = ibHelp.DataNodeToString(dn);
        buffer.push_back(line);
    }
    return buffer;
}

void IberiaDataStore::Load()
{
    Load(_dmFileName);
}

void IberiaDataStore::Load(std::string fileName)
{
    std::vector<std::string> tmpFile;
    tmpFile = ibIO.ReadData(fileName);
    for (size_t i = 0; i < tmpFile.size(); i++)
    {
        DataNode dn = ibHelp.StringToDataNode(tmpFile[i]);
        Add(dn._Key, dn._Value);
    }
}

int IberiaDataStore::Count()
{
    int mapsize = (int)_dataMap.size();
    return mapsize;
}
void IberiaDataStore::Clear()
{
    _dataMap.clear();
}

void IberiaDataStore::SetFileName(std::string fn)
{
    _dmFileName = fn;
}
std::string IberiaDataStore::GetFileName()
{
    return _dmFileName;
}














