#ifndef confreader
#define confreader
    #include <filesystem>
    #include <fstream>
    #include <vector>

    using namespace std;
    using namespace std::filesystem;

    class ConfigLoader {
    private:
    path filename, dirpath, filepath;
    ifstream configFile;
    vector<string> files;
    public:
    ConfigLoader(const path dirpath = "./", const path filename = "config.conf");
    int countlines();
    void parseFiles();
    void displayFiles();
    bool isValidFilename(const string name);
    };
#endif
