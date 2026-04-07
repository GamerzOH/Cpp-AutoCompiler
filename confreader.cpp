#include "confreader.hpp"
#include <ios>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::filesystem;


ConfigLoader::ConfigLoader(const path dirpath, const path filename) {
    this->dirpath = dirpath;
    this->filename = filename;
    this->filepath = dirpath.generic_string() + filename.generic_string();

    parseFiles();
}
int ConfigLoader::countlines() {
    return 1;
}
void ConfigLoader::parseFiles() {
    try{
        configFile.open(filepath);
        if (configFile.is_open()==false) throw "Unable to load file";
    }
    catch(string err) {
        if (err=="Unable to load file") cout<<err;
    }
    catch(...) {
        cout<<"An unexpected error occured!";
        return;
    }
    configFile.seekg(0, ios_base::end);
    int filesize = configFile.tellg();
    configFile.seekg(0, ios_base::beg);
    string line = "";
    while (configFile.tellg()<filesize) {
        getline(configFile, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        if (line[0]!='#' && isValidFilename(line)) files.push_back(line);
    }
    configFile.close();
}

void ConfigLoader::displayFiles() {
    for (int i=0; i<files.size(); i++) {
        cout<<files[i]<<endl;
    }
}

bool ConfigLoader::isValidFilename(const string name) {
    for (int i=0; i<name.size(); i++) {
        if (name[i]=='.') return true;
    }
    return false;
}
