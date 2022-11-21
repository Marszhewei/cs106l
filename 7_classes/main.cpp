#include "strvector.h"
#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::string; using std:: endl;

void print_vec(StrVector& vec)
{
	cout << "{ ";
	for(auto& elem: vec){
		cout << " " << elem << " ";
	}
	cout << " }" << endl;
}

//play around with StrVector here!
int main(int argc, char **argv)
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    cout << "**** Create an empty strvector.\n";
    StrVector sv;
    cout << "Is empty? " << std::boolalpha << sv.empty() << endl;
    cout << "my vector: ";
    print_vec(sv);
    cout << "strvector length: " << sv.length() << endl;

    cout << "\n**** Test push_back() and insert().\n";
    string s;
    size_t idx;
    for (int i = 0; i < 3; ++i) {
        cin >> s;
        sv.push_back(s);
        cout << "Is empty? " << std::boolalpha << sv.empty() << endl;
        print_vec(sv);
        cout << "strvector length: " << sv.length() << endl;
    }
    cin >> s >> idx;
    sv.insert(sv.begin() + idx, s);
    cout << "Is empty? " << std::boolalpha << sv.empty() << endl;
    print_vec(sv);
    cout << "strvector length: " << sv.length() << endl;

    cout << "\n**** Test pop_back() and remove().\n";
    cout << "pop back elems: " << sv.pop_back() << endl;
    cout << "strvector length: " << sv.length() << endl;
    cin >> idx;
    cout << "remove idx: " << idx << " is : " << sv.remove(sv.begin() + idx) << endl;
    cout << "strvector length: " << sv.length() << endl;
    print_vec(sv);

    cout << "\n**** Test clear the whole strvector.\n";
    sv.clear();
    print_vec(sv);
    cout << "Is empty? " << std::boolalpha << sv.empty() << endl;

    cout << "\n**** Test operator[] and constructor.\n";
    s = "hello";
    StrVector sv1(3, s);
    cout << "{ ";
    for (int i = 0; i < 3; ++i)
        cout << ' ' <<  sv1[i] << ' ';
    cout << " }\n";

	return 0;
}