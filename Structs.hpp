//
//  StructsEnums.hpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#ifndef StructsEnums_h
#define StructsEnums_h

#include <string>

struct DataNode
{
    std::string _Key;
    std::string _Value;
};

struct iFile
{
    std::string _FileName;
    std::string _FolderName;
    std::string _Sep;
    OSType _ostype;
};



#endif /* StructsEnums_h */
