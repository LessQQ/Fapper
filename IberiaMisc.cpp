//
//  IberiaMisc.cpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#include "IberiaMisc.hpp"

IberiaMisc::IberiaMisc()
{
}


IberiaMisc::~IberiaMisc()
{
}

bool IberiaMisc::StringToBool(char *str)
{
    std::string result = str;
    if (result == "TRUE" || result == "true")
        return true;
    else
        return false;
}

char *IberiaMisc::BoolToString(bool stat, bool lower)
{
    IberiaMisc ibm;
    
    if (stat)
    {
        std::string result;
        if (!lower)
            result = "TRUE";
        else
            result = "true";
        return ibm.StringToChar(result);
    }
    else
    {
        std::string result;
        if (!lower)
            result = "FALSE";
        else
            result = "false";
        return ibm.StringToChar(result);
    }
}

std::string IberiaMisc::IntToString(int str)
{
    std::string result;
    std::stringstream ss;
    ss << str;
    result.append(ss.str());
    return result;
}

int IberiaMisc::CharToInt(char a[])
{
    int c, sign = 0, offset, n;
    
    if (a[0] == '-')
    {							// Handle negative integers
        sign = -1;
    }
    
    if (sign == -1)
    {							// Set starting position to convert
        offset = 1;
    }
    else
    {
        offset = 0;
    }
    
    n = 0;
    
    for (c = offset; a[c] != '\0'; c++)
    {
        n = n * 10 + a[c] - '0';
    }
    
    if (sign == -1)
    {
        n = -n;
    }
    
    return n;
}

int IberiaMisc::StringToInt(std::string str)
{
    char a[sizeof(str) + 1];
    //strcpy_s(a, str.c_str());
    strcpy(a, str.c_str());
    int result = CharToInt(a);
    return result;
}

char *IberiaMisc::StringToChar(std::string str)
{
    //char* result = strcpy_s((char*)malloc(str.length() + 1), str.c_str());
    char* result = &str[0];
    return result;
}

std::string IberiaMisc::MakeFullFileName(std::string path, std::string sep, std::string fileName)
{
	std::string result = path + sep + fileName;
	return result;
}

DataNode IberiaMisc::StringToDataNode(std::string data)
{
    DataNode dn = StringToDataNode(data, "=");
    return dn;
}
DataNode IberiaMisc::StringToDataNode(std::string data, std::string token)
{
    DataNode dn;
    size_t pos = std::string::npos;
    bool searching = true;
    do
    {
        pos = data.find(token);
        dn._Key = data.substr(0,pos);
        if (std::string::npos != pos)
        {
            dn._Value = data.substr(pos + token.size());
            searching = false;
        }
    } while (searching);

    return dn;
}
std::string IberiaMisc::DataNodeToString(DataNode data)
{
    std::string output = DataNodeToString(data, "=");
    return output;
}
std::string IberiaMisc::DataNodeToString(DataNode data, std::string token)
{
    std::string output;
    output = data._Key + token + data._Value;
    return output;
}















