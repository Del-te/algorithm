#include <iostream>
using namespace std;
void fabo1(){
	int x = 1, y = 2, z;
	cout << "斐波那契数列：" << endl;
	for (int i = 0;i < 20;i++) {
	z = y + x;
	x = y;
	y = z;
//	cout << "x = "<< x << "  y = " << y << "  z = " << z << endl;
	cout << x << endl;
	}
	
}
void fabo2(){
	int x = 1, y = 2;
	cout << "斐波那契数列：" << endl;
	for(int i = 1;i < 10;i++) {
		x = x + y;
		y = y + x;
//		cout << "x = "<< x << "  y = " << y << endl;
		cout << x << endl << y << endl;
	} 
}
int main() {
	fabo1();
	cout<< endl;
	fabo2();	
	return 0;
} 