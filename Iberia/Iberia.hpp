/*
 *  Iberia.hpp
 *  Iberia
 *
 *  Created by Robb on 3/25/17.
 *  Copyright © 2017 Robb Long. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

//#include <unistd.h>
//#include "Iberia/pch.h"

#include "Global.hpp"

#include "Enums.hpp"
#include "Structs.hpp"
#include "IberiaIO.hpp"
#include "IberiaMisc.hpp"
#include "IberiaDataStore.hpp"

MONExternC class Iberia
{
	public:
		IberiaDataStore _dataStore;
		IberiaIO _ibIO;
		IberiaMisc _ibHelp;

        IberiaDataStore _runningConfig;
    
		std::string _fileName;
		
		// These are the ones that should be used during game development
		double CreateDataStore(const char *path, const char *fileName);
		double LoadDataStore(const char *path, const char *fileName);
		double SaveDataStore(const char *path, const char *fileName);

		// For use in apps
		bool Save();

		// Not really needed. Use the ones with paths
		// instead. Keeping around in case.
		bool CreateDS(const char *fileName);
		int  LoadDS(const char *fileName);
		int  SaveDS(const char *fileName);

		// For game engine interface
		int  Contains(const char *key);
		void Add(const char *key, const char *value);
		void Update(const char *key, const char *value);
		const char *Get(const char *key);
		void Remove(const char *key);

		std::vector<std::string> ListData(std::string fileName, KVData kvd);

		// For app interface
		bool Contains(std::string key);
		void Add(std::string key, std::string svalue);
		void Update(std::string key, std::string svalue);
		std::string Get(std::string key);
		void Remove(std::string key);

		void LoadIDS(std::string sfile);

		// Utility type stuff
		void SetFileName(std::string fileName);
		void SetFileName(const char *fileName);
		const char *GetFileName();
};

