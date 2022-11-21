
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// using std::cout;    using std::endl;
// using std::string; using std::cin;

//read numbers from a file
void readNumbers() {
    // Create our ifstream and make it open the file
    std::ifstream fin("res/numbers.txt");
    if (!fin) {
        std::cerr << "open res/numbers.txt error!\n";
        exit(EXIT_FAILURE);
    }

    int val;
    while (fin >> val) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    fin.clear();
    fin.close();
    // Something to store values we get from the stream

        // Extract next number from input
        

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        //print whatever we read
        
}

//read a single word at a time from a file
void readHaikuWord() {
    // Create our ifstream and make it open the file
    std::ifstream fin("res/haiku.txt");
    if (!fin) {
        std::cerr << "open res/haiku.txt error!\n";
        exit(EXIT_FAILURE);
    }

    std::string s;
    char ch;
    while (fin >> s) {
        ch = fin.get();
        std::cout << s << ch;
    }

    fin.clear();
    fin.close();
     // Something to store values we get from the stream

        // Extract next word from input


        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        //print whatever we read

}

void readHaikuLine() {
    // Create our ifstream and make it open the file
    std::ifstream fin("res/haiku.txt");
    if (!fin) {
        std::cerr << "open res/haiku.txt error!\n";
        exit(EXIT_FAILURE);
    }

    std::string s;
    while (getline(fin, s)) {
        std::cout << s << std::endl;
    }

    fin.clear();
    fin.close();
    // Something to store the lines as we get them form the stream

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        //print whatever we read

}



//function for us to play around with cin
void playground() {
    using std::cout;    using std::endl;
    using std::string; using std::cin;
    string line;
    std::ifstream in("res/haiku.txt");
    while(std::getline(in, line)){
        if(in.eof()){
        cout << "eof" << endl;
         // break;
        }
        else if (in.fail()) {
            cout << "fail" << endl;
            // break;
        }
        else cout << line << endl;
        cout << in.eof() << in.fail() << endl;
    }
    cout << in.eof() << in.fail() << endl;

}

int main() {

    // playground();
    readNumbers();

    readHaikuWord();

    readHaikuLine();

    return 0;
}


