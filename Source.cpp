#include "CComplexVector.h"
#include "CComplexVector0.h"
#include "CComplexVector1.h"
#include "AutoTest.hpp"
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "Ouch..." << endl;
		return 0;
	}
	cout << "Yeeeeey!!" << endl;
	ifstream in("input.txt");
	int n = 0;
	in >> n;
	CComplexVector** arr = new CComplexVector * [n];
	std::string* filenames = new std::string[n]();
	int j = 0;
	int s = 0;
	std::string filename;
	for (int i = 0; i < n; i++) {
		in >> j;
		in >> filename;
		in >> s;
		CComplexVector* a;
		if (j == 0) {
			a = new CComplexVector0(s);
		}
		else {
			a = new CComplexVector1(s);
		}
        for (int k = 0; k < s; k++) { //бежим в строках по эл-м
            string cur; //ставим курсор
            in >> cur;
            int l = cur.find('+');
            if (l != string::npos) {
                (*a)[k].re = atoi(cur.substr(0, l).c_str());
                (*a)[k].im = atoi(cur.substr(l + 1, cur.size() - l - 2).c_str());
            }
            else if ((l = cur.find('-')) != string::npos) {
                (*a)[k].re = atoi(cur.substr(0, l).c_str());
                (*a)[k].im = atoi(cur.substr(l, cur.size() - l - 1).c_str());
            }
            else if ((l = cur.find('i')) != string::npos) {
                (*a)[k].re = 0;
                (*a)[k].im = atoi(cur.substr(0, cur.size() - 1).c_str());
            }
            else {
                (*a)[k].re = atoi(cur.c_str());
                (*a)[k].im = 0;
            }
        }
        arr[i] = a;
        filenames[i] = filename;
    }
	for (int i = 0; i < n; i++) {
		arr[i]->output(filenames[i].c_str());
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
		filenames[i].clear();
	}
	delete[] arr;
	delete[] filenames;
	return 0;
}
