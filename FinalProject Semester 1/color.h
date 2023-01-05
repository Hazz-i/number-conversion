#pragma once

#include <Windows.h>

// fungsi: set_color()
//   Set warna depan dan warna latar teks.
//   Warna antara 0-7 dengan kecerahan standar,
//   antara 8-15 warna sama dengan kecerahan lebih.
// tipe: void
// arg.: WORD fc - warna depan (0-15)
//       WORD bc - warna latar (0-15)
void set_color(WORD fc, WORD bc)
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	// warna latar nilainya sama dengan warna depan (0-15)
	// tetapi digeser dengan operasi bitshift 4 bit ke kanan
	SetConsoleTextAttribute(hwnd, fc + (bc << 4));
}

// fungsi: set_xy()
//   Meletakkan kursor pada posisi x, y di layar konsol.
// tipe: void
// arg.: SHORT x - posisi x
//       SHORT y - posisi y
void set_xy(SHORT x, SHORT y)
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hwnd, { x, y });
}