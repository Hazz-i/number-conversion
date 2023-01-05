#include "color.h"
#include "menu.cpp"
#include "rekursif.h"

using namespace std;

// menu - menu konversi yang terdapat
void binner();			// fungsi konversi bilangan binner
void octal();			// fungsi konversi bilangan octal
void desimal();			// fungsi konversi bilangan desimal
void hexa();			// fungsi konversi bilangan hexa
void history();			// fungsi untuk melihat riwayat
void keluar();			// fungsi exit
void ifc_main();		// interface 1
void ifc_sub();			// interface 2
void loading();			// loading interface

// rekursif konversi
int bintodec(string n);		// konversi binner ke desimal
int octtodec(int oct);		// konversi octal ke desimal
int hextodec(char hex[]);	// konversi hexa ke desimal
string dectobin(int dec);	// konversi desimal ke binner
string dectooct(int dec);	// konversi desimal ke octal
string dectohex(int dec);	// konversi desimal ke hexa

// vector untuk menyimpan data
struct in_bin { string input; string output; };
struct in_oct { string input; string output; };
struct in_dec { string input; string output; };
struct in_hex { string input; string output; };
vector<in_bin>bin;
vector<in_oct>octo;
vector<in_dec>deci;
vector<in_hex>hexd;
string idx_bin[];


int main() {
	system("cls");

	ifc_main();
	set_xy(74, 10);
	cout << "Konversi Bilangan";

	menu ex;
	int menu;
	ex.set_xy(73, 12);
	ex.set_color(ex.GREEN);
	menu = ex.Gmenu("[1] Konversi Binner", "[2] Koversi Octal", "[3] Konversi Desimal", "[4] Konversi Hexa", "[5] Riwayat", "[6] Keluar");
	switch (menu)
	{
	case 0:
		binner();
	case 1:
		octal();
	case 2:
		desimal();
	case 3:
		hexa();
	case 4:
		history(); return main();
	case 5:
		keluar();
	}
}

// Operasi Konversi Bilangan Binner
// Avg.	Berisi Bermacam Konvesrsi Bilangan Binner
//		Type Void
	void binner() {
	system("cls");

	ifc_main();
	set_xy(75, 10);
	cout << "Konversi Binner";

	menu ex;
	int menu;
	ex.set_xy(73, 13);
	ex.set_color(ex.TURQUOISE);
	menu = ex.Gmenu("[1] Binner ke Octal", "[2] Binner ke Desimal", "[3] Binner Hexa ", "[4] Kembali", "[5] Keluar");
	switch (menu)
	{
	case 0:
		while (true) {
			system("cls");
			ifc_sub();

			string n;
			set_xy(77, 8);
			cout << "Binner ke Octal";
			set_xy(25, 14);
			cout << "Masukan Bilangan Binner: ";
			getline(cin, n);
			if (n == "0") binner();
			int dec = bintodec(n);
			loading();

			set_xy(59, 27);
			cout << "Konversi Dari biner " << n << " Konversi decimalnya adalah " << dectooct(dec) << endl;
			system("pause > null");

			// memasukan kedalam vector bin 
			string out = dectooct(dec);
			bin.push_back({n, out});
		}
	case 1:
		while (true) {
			system("cls");
			ifc_sub();

			string n;
			set_xy(77, 8);
			cout << "Binner ke Desimal";
			set_xy(25, 14);
			cout << "Masukan Bilangan Binner: ";
			getline(cin, n);
			if (n == "0") binner();

			loading();
			set_xy(59, 27);
			cout << "Konversi Dari biner " << n << " Konversi decimalnya adalah " << bintodec(n) << endl;
			system("pause > null");

			// masukan kedalam vecto bin
			string out = to_string(bintodec(n));		// meengubah integer menjadi string
			bin.push_back({ n, out });
		}
	case 2:
		while (true) {
			system("cls");
			ifc_sub();

			string n;
			set_xy(77, 8);
			cout << "Binner ke Hexa";
			set_xy(25, 14);
			cout << "Masukan Bilangan Binner: ";
			getline(cin, n);
			if (n == "0") binner();
			int dec = bintodec(n);					// n akan di konversi menjadi desimal terlebih dahulu
													// kemudian akan di konversi mejadi hexa
			loading();
			set_xy(59, 27);
			cout << "Konversi Dari biner " << n << " Konversi hexa adalah " << dectohex(dec) << endl;
			system("pause > null");
			
			// masukan ke dalam vector bin
			string out = dectohex(dec);
			bin.push_back({ n, out });

		}
	case 3:
		main();
	case 4:
		keluar();
	}
}

// Operasi Konversi Bilangan Octal
// Avg.	Berisi Bermacam Konvesrsi Bilangan Octal
//		Type Void
	void octal() {
		system("cls");

		ifc_main();
		set_xy(75, 10);
		cout << "Konversi Octal";

		menu ex;
		int menu;
		ex.set_xy(73, 13);
		ex.set_color(ex.RED);
		menu = ex.Gmenu("[1] Octal ke Binner", "[2] Octal ke Desimal", "[3] Octal ke Hexa", "[4] Kembali", "[5] Keluar");
		switch (menu)
		{
		case 0:
			while (true) {
				system("cls");
				ifc_sub();

				int n;
				set_xy(77, 8);
				cout << "Octal ke Binner";
				set_xy(25, 14);
				cout << "Masukan Bilangan Octal: ";
				cin >> n;
				if (n == 0) octal();
				int dec = octtodec(n);

				loading();
				set_xy(59, 27);
				cout << "Konversi Dari biner " << n << " Konversi binner adalah " << dectobin(dec) << endl;
				system("pause > null");

				string in = to_string(n);
				string out = dectobin(dec);
				octo.push_back({ in, out });
			}
		case 1:
			while (true) {
				system("cls");
				ifc_sub();

				int n;
				
				set_xy(77, 8);
				cout << "Octal ke Desimal";
				set_xy(25, 14);
				cout << "Masukan Bilangan Octal: ";
				cin >> n;
				if (n == 0) octal();

				loading();
				set_xy(59, 27);
				cout << "Konversi Dari biner " << n << " Konversi desimal adalah " << octtodec(n) << endl;
				system("pause > null");

				string in = to_string(n);
				string out = to_string(octtodec(n));
				octo.push_back({ in, out });
			}
		case 2:
			while (true) {
				system("cls");
				ifc_sub();

				int n;
				set_xy(77, 8);
				cout << "Octal ke Hexa";
				set_xy(25, 14);
				cout << "Masukan Bilangan Octal: ";
				cin >> n;
				if (n == 0) octal();
				int dec = octtodec(n);

				loading();
				set_xy(59, 27);
				cout << "Konversi Dari biner " << n << " Konversi hexa adalah " << dectohex(dec) << endl;
				system("pause > null");

				string in = to_string(n);
				string out = dectohex(dec);
				octo.push_back({ in, out });
			}
		case 3:
			main();
		case 4:
			keluar();
		}
	}

// Operasi Konversi Bilangan Desimal
// Avg.	Berisi Bermacam Konvesrsi Bilangan Desimal
//		Type Void
	void desimal() {
		system("cls");

		ifc_main();
		set_xy(75, 10);
		cout << "Konversi Desimal";

		menu ex;
		int menu;
		ex.set_xy(73, 13);
		ex.set_color(ex.RED);
		menu = ex.Gmenu("[1] Desimal ke Binner", "[2] Desimal ke Octal", "[3] Desimal ke Hexa", "[4] Kembali", "[5] Keluar");
		switch (menu)
		{
		case 0:
			while (true) {
				system("cls");
				ifc_sub();

				int dec;
				set_xy(77, 8);
				cout << "Desimal ke Binner";
				set_xy(25, 14);
				cout << "Masukan Bilangan Desimal: ";
				cin >> dec;
				if(dec == 0) desimal();

				loading();
				set_xy(59, 27);
				cout << "Konversi Dari desimal " << dec << " Konversi Binnernya adalah " << dectobin(dec);
				system("pause > null");

				string in = to_string(dec);
				string out = dectobin(dec);
				deci.push_back({ in, out });
			}
		case 1:
			while (true) {
				system("cls");
				ifc_sub();

				int dec;
				set_xy(77, 8);
				cout << "Desimal ke Octal";
				set_xy(25, 14);
				cout << "Masukan Bilangan Desimal: ";
				cin >> dec;
				if (dec == 0) desimal();

				loading();

				set_xy(61, 27);
				cout << "Konversi Dari desimal " << dec << " Konversi Octalnya adalah " << dectooct(dec);
				system("pause > null");

				string in = to_string(dec);
				string out = dectooct(dec);
				deci.push_back({ in, out });
			}
		case 2:
			while (true) {
				system("cls");
				ifc_sub();

				int dec;
				set_xy(77, 8);
				cout << "Desimal ke Hexa";
				set_xy(25, 14);
				cout << "Masukan Bilangan Desimal: ";
				cin >> dec;
				if (dec == 0) desimal();

				loading();

				set_xy(61, 27);
				cout << "Konversi Dari desimal " << dec << " Konversi hexanya adalah " << dectohex(dec);
				system("pause > null");

				string in = to_string(dec);
				string out = dectohex(dec);
				deci.push_back({ in, out });
			}
		case 3:
			main();
		case 4:
			keluar();
		}
	}

// Operasi Konversi Bilangan Hexadesimal
// Avg.	Berisi Bermacam Konvesrsi Bilangan Hexadesimal
//		Type Void
	void hexa() {
		system("cls");

		ifc_main();
		set_xy(75, 10);
		cout << "Konversi Hexa";

		menu ex;
		int input;
		ex.set_xy(73, 13);
		ex.set_color(ex.PURPLE);
		input = ex.Gmenu("[1] Hexa ke Binner", "[2] Hexa ke Octal", "[3] Hexa ke Desimal", "[4] Kembali", "[5] Keluar");
		switch (input)
		{
		case 0:
			while (true) {
				system("cls");
				ifc_sub();

				char hex[100];
				set_xy(77, 8);
				cout << "Hexa ke Binner";
				set_xy(25, 14);
				cout << "Masukan Bilangan Hexa: ";
				cin >> hex;
				string e = string(hex);
				if (e == "0") hexa();

				int dec = (hextodec(hex));

				loading();
				set_xy(61, 27);
				cout << "Konversi dari Hexa " << hex << " Konversi binner adalah " << dectobin(dec) << endl;
				system("pause > null");

				string out = dectobin(dec);
				hexd.push_back({ e, out});
			};
		case 1:
			while (true) {
				system("cls");
				ifc_sub();

				char hex[100];
				set_xy(77, 8);
				cout << "Hexa ke Octal";
				set_xy(25, 14);
				cout << "Masukan Bilangan Hexa: ";
				cin >> hex;
				string e = string(hex);
				if (e == "0") hexa();

				int dec = (hextodec(hex));

				loading();
				set_xy(61, 27);
				cout << "Konversi dari Hexa " << hex << " Konversi octal adalah " << dectooct(dec) << endl;
				system("pause > null");

				string out = dectooct(dec);
				hexd.push_back({ e, out });
			};
		case 2:
			while (true) {
				system("cls");
				ifc_sub();

				char hex[100];
				set_xy(77, 8);
				cout << "Hexa ke Desimal";
				set_xy(25, 14);
				cout << "Masukan Bilangan Hexa: ";
				cin >> hex;
				string e = string(hex);
				if (e == "0") hexa();

				loading();
				set_xy(61, 27);
				cout << "Konversi dari Hexa " << hex << " Konversi desimal adalah " << (hextodec(hex)) << endl;
				system("pause > null");

				string out = to_string(hextodec(hex));
				hexd.push_back({ e, out });
			};
		case 3:
			main();
		case 4:
			keluar();
		}
	}

// untuk menampilkan riwayat konversi
// Avg. Type void
	void history() {
		system("cls");
		for (int i = 5; i <= 150; ++i) {
			set_xy(i, 2);
			cout << "---------------";
		}
		set_xy(78, 1);
		cout << "HISTORY";

		set_xy(11, 3);
		cout << "Konversi Binner\n";
		for (auto p : bin) {
			cout << setw(10) << p.input;
			cout << setw(20) << p.output;
			cout << endl;
		}
		set_xy(55, 3);
		cout << "Konversi Octal\n";
		for (auto p : octo) {
			cout << setw(54) << p.input;
			cout << setw(20) << p.output;
			cout << endl;
		}
		set_xy(100, 3);
		cout << "Konversi Desimal\n";
		for (auto p : deci) {
			cout << setw(99) << p.input;
			cout << setw(20) << p.output;
			cout << endl;
		}

		set_xy(145, 3);
		cout << "Konversi Hexa\n";
		for (auto p : hexd) {
			cout << setw(144) << p.input;
			cout << setw(20) << p.output;
			cout << endl;
		}
		system("pause > null");
	}


// interface
// Avg.	type - void
	void keluar() {
		system("cls");
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