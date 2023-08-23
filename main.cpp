#include <iostream>

#include "Iberia.hpp"
#include "IberiaIO.hpp"

bool CheckConfigFile();

int main(int argc, char* argv[])
{
    Iberia iberia;

    if (CheckConfigFile())
    {
        iberia.LoadDataStore("/etc/fap/","fapper.ids");
    }
    else
    {
        iberia.CreateDataStore("/etc/fap/", "fapper.ids");
        iberia.Add("errors", "~/.fap/error.log");
        iberia.Add("bank","~/.fap/bank.ids");
        iberia.Add("release", "~/.fap/release");
        iberia.Add("tmp","~/.fap/tmp");
        iberia.Save();
    }

    return 0;
}

bool CheckConfigFile()
{
    IberiaIO iberiaIo;
    return iberiaIo.FileExist("/etc/fap/fapper.ids");
}

