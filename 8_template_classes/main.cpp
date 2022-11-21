#include "realvector.h" // Change this to "realvector.h" if you want to use your solution!
#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::string; using std:: endl;

void print_vec(const RealVector<std::string>& vec){
	cout << "{ ";
	for(auto it = vec.cbegin(); it != vec.cend(); ++it){
		cout << ' ' << *it << ' ';
	}
	cout << " }" << endl;
}

//play around with RealVector here!
int main(){
	/* //make an empty vector
	RealVector<int> myVec;
	cout << "My vector: ";
	print_vec(myVec);

	cout << "Enter [ELEM] [INDEX]:" << endl;
	int to_add;
	size_t index;
	while(cin >> to_add >> index){
		myVec.insert(index, to_add);
		// myVec.insert(myVec.begin() + index, to_add);
		cout << "My vector: ";
		//print vector:
		print_vec(myVec);

		//next prompt
		cout << "Enter [ELEM] [INDEX]:" << endl;
	} */
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    cout << "**** Create an empty strvector.\n";
    RealVector<std::string> sv;
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
    RealVector sv1(3, s);
    cout << "{ ";
    for (int i = 0; i < 3; ++i)
        cout << ' ' <<  sv1[i] << ' ';
    cout << " }\n";

	return 0;
}