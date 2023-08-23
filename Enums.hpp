//
//  StructsEnums.hpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#ifndef Enums_hpp
#define Enums_hpp

#include <string>

enum OSType
{
    UNIX = 1,
    iOS = 2,
    ANDROID =3,
    WINNT = 9
};

enum KVData
{
    Key,
    Value,
    Both
};

enum qqCommand
{
    INIT,
    ADD,
    REMOVE,
    BUILD,
    CLEAN,
    SET,
    UNSET,
    UPDATE,
    LIST,
    FILES,
    SETTINGS,
    VERSION,
    INSTALL,
    PUSH,
    PULL,
    COMMIT,
    ERRORX
};

#endif /* StructsEnums_h */
