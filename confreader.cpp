#include <ios>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::filesystem;

class ConfigLoader {
    path filename, dirpath, filepath;
    ifstream configFile;
    vector<string> files;
    public:
    ConfigLoader(const path dirpath = "./", const path filename = "config.conf") {
        this->dirpath = dirpath;
        this->filename = filename;
        this->filepath = dirpath.generic_string() + filename.generic_string();

        parseFiles();
    }
    int countlines() {
       return 1;
    }
    void parseFiles() {
        configFile.open(filepath);
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

    void displayFiles() {
        for (int i=0; i<files.size(); i++) {
            cout<<files[i]<<endl;
        }
    }

    bool isValidFilename(string name) {
        for (int i=0; i<name.size(); i++) {
            if (name[i]=='.') return true;
        }
        return false;
    }
};
