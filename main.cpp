#include <iostream>

#include "Iberia/Iberia.hpp"
#include "Iberia/IberiaIO.hpp"

const std::string path("/etc/fap");
const std::string fileName("fap.config");

bool CheckConfigFile();
void CreateBase();
void Help();

int main(int argc, char* argv[]) {

    Iberia iberia;

    if (CheckConfigFile()) {
        iberia.LoadDataStore(path.c_str(), fileName.c_str());
    }
    else {
        std::cout << "fap.config not found!" << std::endl;
        //exit(1);
    }

    if (argc < 2) {
        Help();
        exit(1);
    }

    std::string command(argv[1]);
    if (command == "create") {
        iberia.CreateDataStore(path.c_str(), fileName.c_str());
        iberia.Add("errors", "~/.fap/error.log");
        iberia.Add("bank","~/.fap/bank.ids");
        iberia.Add("release", "~/.fap/release");
        iberia.Add("tmp","~/.fap/tmp");
        iberia.SaveDataStore(path.c_str(), fileName.c_str());
    }
    else if (command == "get") {
        if (iberia.Contains(argv[2])) {
            std::cout << iberia.Get(argv[2]) << std::endl;
        }
        else {
            std::cout << "not found!" << std::endl;
        }
    }
    else if (command == "set") {
        iberia.Add(argv[2],argv[3]);
        iberia.SaveDataStore(path.c_str(), fileName.c_str());
    }
    else if (command == "remove") {
        iberia.Remove(argv[2]);
    }
    else {
        std::cout << "unknown parameter!" << std::endl;
        exit(1);
    }

    return 0;
}

bool CheckConfigFile() {
    IberiaIO iberiaIo;
    std::string fn = path + "/" + fileName;
    return iberiaIo.FileExist(fn.c_str());
}
void CreateBase() {
    Iberia iberia;

    iberia.CreateDataStore(path.c_str(), fileName.c_str());
    iberia.Add("errors", "~/.fap/error.log");
    iberia.Add("bank","~/.fap/bank.ids");
    iberia.Add("release", "~/.fap/release");
    iberia.Add("tmp","~/.fap/tmp");
    iberia.SaveDataStore(path.c_str(), fileName.c_str());
}
void Help() {
    std::cout << "not enough parameters!" << std::endl;
}

