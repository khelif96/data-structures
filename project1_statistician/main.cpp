#include <iostream>
using namespace std;
#include "stats.h"

int main(){
	statistician s1;
	statistician s2;
	for(int i = 0; i <= 50; i++){
		s1.next(i);
	}
	for(int i = 50; i<= 100; i++){
		s2.next(i);
	}
	cout << "s.mean " << s1.mean() << endl;
	cout << "s2.mean " << s2.mean() << endl;
	cout << "s.minimum " << s1.minimum() << endl;
	cout << "s2.minimum " << s2.minimum() <<  endl;
	cout << "s.maximum " << s1.maximum() << endl;
	cout << "s2.maximum " << s2.maximum() << endl;
	cout << "s.length " << s1.length() << endl;
	cout << "s2.length " << s2.length() << endl;
	statistician s3;
	s3 = s1 + s2;
	cout << "s3.length " <<  s3.length() << endl;
	cout << "s3.min " << s3.minimum() << endl;
	cout << "s3.max " << s3.maximum() << endl;
	statistician s4;
	s4 = 2*s1;
	cout << "s4.length " << s4.length() << endl;;
	cout << "s4.min " << s4.minimum() << endl;
	cout << "s4.max " << s4.maximum() << endl;
	cout << "s4.mean " << s4.mean() << endl;
	// if(s1 == s2)
	// 	cout << "Same Value" << endl;
	// else
	// 	cout << "Fail " << endl;
	//cout << "equivelance " << s1 == s2 << endl;
	return 0;
}
