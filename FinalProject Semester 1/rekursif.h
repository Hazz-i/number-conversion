#include<iostream>
#include<string>

using namespace std;

int bintodec(string n) {
    int dec = 0;
    int base = 1;
    int len = n.length();

    for (int i = len - 1; i >= 0; i--) {
        if (n[i] == '1')
            dec += base;
        base *= 2;
    }

    return dec;
}

int octtodec(int n)
{
    int dec = 0, i = 0, rem;
    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(8, i);
        ++i;
    }
    return dec;
}

string dectobin(int dec) {
    if (dec == 0) {
        return "0";
    }
    else if (dec == 1) {
        return "1";
    }
    else {
        return dectobin(dec / 2) + char(dec % 2 + '0');
    }
}

string dectooct(int dec) {
    if (dec == 0) {
        return "0";
    }
    else {
        return dectooct(dec / 8) + char(dec % 8 + '0');
    }
}

string dectohex(int dec) {
    if (dec == 0) {
        return "0";
    }
    else {
        static const char hex_digits[] = "0123456789ABCDEF";
        return dectohex(dec / 16) + hex_digits[dec % 16];
    }
}

int hextodec(char hex[])
{
    if (strlen(hex) == 0)
        return 0;

    // Mengambil karakter pertama dari hexadesimal
    char digit = hex[0];

    // Menghapus digit pertama dari string hexadesimal
    hex++;

    // Panggil fungsi rekursif untuk sisa string
    int dec = hextodec(hex);

    // Tambahkan hasil konversi digit ke desimal ke hasil panggilan rekursif
    if (digit >= '0' && digit <= '9')
        dec += (digit - '0') * pow(16, strlen(hex));
    else if (digit == 'A' || digit == 'a')
        dec += 10 * pow(16, strlen(hex));
    else if (digit == 'B' || digit == 'b')
        dec += 11 * pow(16, strlen(hex));
    else if (digit == 'C' || digit == 'c')
        dec += 12 * pow(16, strlen(hex));
    else if (digit == 'D' || digit == 'd')
        dec += 13 * pow(16, strlen(hex));
    else if (digit == 'E' || digit == 'e')
        dec += 14 * pow(16, strlen(hex));
    else if (digit == 'F' || digit == 'f')
        dec += 15 * pow(16, strlen(hex));

    return dec;
}