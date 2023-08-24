//
//  IberiaDataStore.hpp
//  Iberia
//
//  Created by Robb on 3/26/17.
//  Copyright © 2017 Robb Long. All rights reserved.
//

#ifndef IberiaDataStore_hpp
#define IberiaDataStore_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Enums.hpp"
#include "Structs.hpp"
#include "IberiaIO.hpp"
#include "IberiaMisc.hpp"

class IberiaDataStore
{
private:
    int dataMapID;
    IberiaIO ibIO;
    IberiaMisc ibHelp;
    
    std::map<std::string, std::string> _dataMap;
    std::string _dmFileName;
public:
    bool Contains(std::string key);
    void Add(std::string key, std::string value);
    std::string Get(std::string key);
    void Update(std::string key, std::string value);
    void Remove(std::string key);
    
    void SetFileName(std::string fn);
    std::string GetFileName();
    
    void Save();
    void Save(std::string fileName);
    void Load();
    void Load(std::string fileName);

    std::vector<std::string> ListDS(std::string fileName);
    
    int Count();
    void Clear();
    
};

#endif /* IberiaDataStore_hpp */
