//
//  IberiaMisc.hpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#ifndef IberiaMisc_hpp
#define IberiaMisc_hpp

#include <stdio.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <list>
#include <vector>

#include "Enums.hpp"
#include "Structs.hpp"

class IberiaMisc
{
public:
    IberiaMisc();
    ~IberiaMisc();
    
    // Helpers
    bool StringToBool(char *str);
    char *BoolToString(bool stat, bool lower = false);
    std::string IntToString(int str);
    int CharToInt(char a[]);
    int StringToInt(std::string str);
    char *StringToChar(std::string str);

	std::string MakeFullFileName(std::string path, std::string sep, std::string fileName);
    
    // Dealing with DataNodes
    DataNode StringToDataNode(std::string data);
    DataNode StringToDataNode(std::string data, std::string token);
    std::string DataNodeToString(DataNode data);
    std::string DataNodeToString(DataNode data, std::string token);
};

#endif /* IberiaMisc_hpp */
