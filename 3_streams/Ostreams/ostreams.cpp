
//What do we need to include?
#include <iostream>
#include <string>
#include <fstream>

//No using namespace std;!!!!
using std::cout;
using std::endl;
using std::string;

//function to write num to any ostream
void write_to_any_ostream(std::ostream &out, int number)
{
    out << number << std::endl;
}

int main() {
    // Write an int to the user's console.
    int myNum = 42;
    cout << "The answer is: " << myNum << endl;

    // Write an int to a file.
    std::ofstream out_stream("out.txt");
    out_stream << "The answer is: " << myNum << endl;
    out_stream.close();
    

    // Write method to take any ostream
    std::ofstream fout("out.txt", std::ios_base::app);
    write_to_any_ostream(fout, 520);
    fout.close();
   
    return 0;
}
