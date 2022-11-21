#include <iostream>
#include <sstream>

using std::cout;    using std::endl;
using std::cin;     using std::string;


string IntegerToString(int myInt) {
    /*
     * We'll specifically use an ostringstream, which is just a
     * stringstream that you can only put things into.
     */

    /*
     * Putting the int into the ostringstream will convert
     * it into a string format.
     */
    std::ostringstream oss;
    oss << myInt;


    /* Ask for the string inside the ostringstream. */
    return oss.str();
}

int StringToInteger(const string& str) {
    /*
     * We'll specifically use an istringstream, which is just a
     * stringstream that you can only get things from.
     *
     * You can set its internal string when creating it or by doing
     * converter.str("string_to_set");
     */
    std::istringstream iss;
    int res;

    /*
     * Try getting an int from the stream. If this is not succesful
     * then user input was not a valid input.
     */
    if (iss >> res) {
    
        /*
         * See if we can extract a char from the stream.
         * If so, the user had junk after a valid int in their input.
         */
        char ch;
        if (iss >> ch) {
            /*
             * Throwing an error is a way of propogating up the funcion
             * callstack that something went wrong. Previous functions can
             * anticipate such an error and catch it. In this case, we will
             * just let the thrown domain_error propogate up until it terminates
             * the program.
             *
             * A domain_error is defined in the standard namespace as an error
             * to signal that the input arguments to the function were not valid.
             */
            throw std::domain_error("unexcept input character.");
        }
        return res;
    }
    
    /* If read unsuccessful, throw a domain error with a helpful error message. */
    throw std::domain_error("unexpected input value.");
    // return 0;
}

int getInteger() {
    while (true) {
        /* First we get a line of input from the user. */
        std::string input;
        getline(std::cin, input);
        /*
         * We'll  use an istringstream because we only want to pull data
         * out of the stream once we have put the string's contents in it.
         */
        std::istringstream iss(input);
        int res;
        /*
         * Try getting an int from the stream. If this is not succesful
         * then user input was not a valid input.
         */
        if (iss >> res) {
            /*
             * See if we can extract a char from the stream.
             * If so, the user had junk after a valid int in their input.
             */
            char ch;
            if (iss >> ch) {
                std::cerr << "unexpected input character.\n";
            } else {
            /*
             * Input was succesfully converted to int with no
             * trailing stuff at the end.
             */
                return res;
            }
        }
    }
}

int main() {
   int x = getInteger();
   cout << "We got: " << x << endl;

}
