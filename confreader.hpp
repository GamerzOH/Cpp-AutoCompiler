#ifndef confreader
#define confreader
    #include <filesystem>
    #include <fstream>
    #include <vector>

    using namespace std;
    using namespace std::filesystem;

    class ConfigLoader{
    private:
    path filename, dirpath, filepath;
    ifstream configFile;
    vector<string> files;
    public:
    ConfigLoader();
    int countlines();
    void parseFiles();
    void displayFiles();
    bool isValidFilename();
    };
#endif
