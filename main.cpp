#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool isFile(char* cont) {
    string cont_str = cont;
    if (cont_str.find(".")!=string::npos) return true;
    else return false;
}

// class Command {
//     string start;
//     vector<string> files;

//     public:
//     Command(char* start = "g++ ", char* mainfile = "./main.cpp") {
//         this->start = start;
//         this->files.push_back(mainfile);
//     }

//     int run() {
//         string cmd = "";
//         cmd.append(start);
//         for (int i=0; i<files.size(); i++) {
//             cmd.append(files[i]);
//             cmd.append(" ");
//         }
//         cmd.append("-o")
//     }
// };

int main(int argc, char** argv) {
    if (argc>1) {
        string cmdbuild = "";
        string runcmd = "./main";
        cmdbuild.append("g++ ./main.cpp ");
        if (strcmp(argv[1], "brun")) {
            cmdbuild.append(" -o ./main");
            system(cmdbuild.c_str());
            system(runcmd.c_str());
        }
        else if (strcmp(argv[1], "run")) {
            system(runcmd.c_str());
        }
        else if (strcmp(argv[1], "add")) {
            for (int i=1; i<argc; i++) {
                if (isFile(argv[i])) cmdbuild.append(argv[i]);
                else break;
            }
        }
    }

    return 0;
}
