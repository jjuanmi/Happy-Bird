#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream archi("../data.dat",ios::binary|ios::out|ios::trunc);
	int a,b,c,d;
	a = 0;
	b = 0;
	c = 1;
	d = 1;
	archi.write(reinterpret_cast<char*>(&a),sizeof(a));
	archi.write(reinterpret_cast<char*>(&b),sizeof(b));
	archi.write(reinterpret_cast<char*>(&c),sizeof(c));
	archi.write(reinterpret_cast<char*>(&d),sizeof(d));

	
	
	return 0;
}

