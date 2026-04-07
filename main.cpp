#include <iostream>
#include "confreader.hpp"

using namespace std;

void followConfig() {

}

int main(int argc, char** argv) {
    ConfigLoader loader;

    if (argc>1) {
        cout<<argv[1];
    }
    else {
        followConfig();
    }

    return 0;
}
