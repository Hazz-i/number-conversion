#include<iostream>
#include "color.h"

using namespace std;

void keluar() {
	system("cls");
	set_xy(73, 15);
	cout << "Hatur Nuwun A\t^_^";
	cout << "\n\n\n\n";
	exit(0);
}
void ifc_main() {
	set_xy(50, 8);
	cout << "=================================================================";
	set_xy(50, 19);
	cout << "=================================================================";
	set_xy(65, 20);
	cout << "Gunakan Arrow Key untuk memilih menu";

	for (int i = 9; i < 19; ++i) {
		set_xy(50, i);
		cout << "|" << endl;
	}
	for (int i = 9; i < 19; ++i) {
		set_xy(114, i);
		cout << "|" << endl;
	}
}
void ifc_sub() {
	for (int i = 15; i <= 140; ++i) {
		set_xy(i, 5);
		cout << "---------------";
	}
	for (int i = 15; i <= 140; ++i) {
		set_xy(i, 35);
		cout << "---------------";
	}
	for (int i = 6; i < 35; ++i) {
		set_xy(21, i);
		cout << "|" << endl;
	}
	for (int i = 6; i < 35; ++i) {
		set_xy(148, i);
		cout << "|" << endl;
	}
	set_xy(76, 36);
	cout << "Masukan 0 untuk Kembali";
	set_xy(65, 9);
	cout << "=======================================";
}
void loading() {
	set_xy(75, 25);
	for (int i = 0; i < 20; ++i) {
		cout << char(219);
		Sleep(50);
	}
}