#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char *argv[]) {
    // File and word vars
    fstream file;
    string word;
    int count = 0;

    // Give values
    string filename = argv[1];
    regex reg(argv[2]);

    //Open file
    file.open(filename.c_str());

    // Read file
    if (file.is_open()) {
        while (file >> word) {
            if (regex_search(word, reg)) {
                count++;
            }
        }
        cout << "The file " << argv[1] << " contains " << count << " words containing the motive " << argv[2] << endl;
        file.close();
        return 0;
    }
    else {
        cout << "The file " << argv[1] << " could not be opened." << endl;
        return 1;
    }
}
