//Works for c++ version 17 or higher
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace filesystem; //C++17 library for working with files and directories.

int main(){

    vector<string> fileCollection;
    size_t entry_length=3;
    string path= "."; //current directory.

    // Iterate over the std::filesystem::directory_entry elements using `auto`
    for (auto const& dir_entry : recursive_directory_iterator(path)){ 
        cout << dir_entry << '\n';
        fileCollection.push_back(dir_entry.path().string()); // Add all the directory paths ,which gets converted to string, to vector.
        //recursive_directory_iterator gives you a std::filesystem::directory_entry, not a std::string.
    }

    string searchWord;
    cout<<"What are you searching for?"<<endl;
    getline(cin, searchWord);
    for(int i=0;i<fileCollection.size();i++){
        ifstream file(fileCollection[i]); //  Open files one by one.
        
        string stringInFiles;
        vector<string> linesOfFile;
        while(getline(file, stringInFiles)){
            linesOfFile.push_back(stringInFiles); //store strings into vector.
        }

        for(size_t a=0; a<linesOfFile.size(); a++){
            size_t found;
            found=linesOfFile[a].find(searchWord);//searches for searchWord
            if (found != string::npos) {
            auto matchedLineIndex = static_cast<int>(a) + 1; 
            cout<<"\n--------------------------------------------------------------------\n";
            cout<<fileCollection[i]<<endl;
            cout<<"Line "<< matchedLineIndex << ": " << linesOfFile[a]<<endl; //Shows the line, string and file where 'searchWord' is.
            }

        file.close();
        }
    }
    return 0;
}

