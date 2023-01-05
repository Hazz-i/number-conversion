// membuaat menu hightlight ala ala 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>

// class needs std namespace as well

using namespace std;

// How to use this class:
//		You may refer to the main function for a quick hint from the comments there as to what this function does and how it works.
//		But I recommend that you read this detailed "how to use" in order to get the max out of this class.

//		The main function in this class is called Gmenu();
//		it takes up to 10 strings, prints them on the screen on the form of a menu, waits for the user to choose one of the strings
//		and returns a value that corresponds to the user's choice (from 0 to 9).

// Options this class provides:
//		- This class -by default- clears the screen when displaying a menu. However member function clear_screen(); provides an option to clear or not
//		to clear the screen.
//		To clear the screen: clear_screen(true);
//		Not to clear the screen: clear_screen(false);

//		- This class provides an option to set the coordinates of the menu on the screen (it is (33, 5) by default) using set_xy(); function. just sent the postion where you
//		want your menu to be. for example: set_xy(20, 4);

//		- The class provides an option to change the color of it's theme, using the function set_color(); it takes one of five strings:
//		"red", "green", "turquoise", "yellow" and "purple".
//		for example: set_color("red");

//									THAT'S ALL ENJOY YOUR CODING, THANK YOU :)

class menu
{
private:
#define Up 72
#define Down 80
#define Enter 13

    int m_x;
    int m_y;
    int menu_color;
    bool m_clr;
    string str[10];

    void m_gotoxy(short x, short y)
    {
        COORD coord = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    void hidecursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 10;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
    }
    void showcursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 10;
        info.bVisible = TRUE;
        SetConsoleCursorInfo(consoleHandle, &info);
    }

public:
    //"red", "green", "turquoise", "yellow" and "purple"
    const int RED = 12;
    const int GREEN = 10;
    const int TURQUOISE = 11;
    const int YELLOW = 9;
    const int PURPLE = 13;

    void set_xy(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    void clear_screen(bool clr)
    {
        m_clr = clr;
    }
    void set_color(int color)
    {

        switch (color)
        {
        case 12:
            menu_color = 12;
            break;
        case 10:
            menu_color = 10;
            break;
        case 11:
            menu_color = 11;
            break;
        case 14:
            menu_color = 14;
            break;
        case 13:
            menu_color = 13;
            break;
        }
    }

     menu()
    {
        m_x = 33;
        m_y = 5;
        m_clr = false;
        menu_color = 12;
        for (int i = 0; i < 10; i++)
            str[i] = "";
    }

    int Gmenu(string str1, string str2, string str3 = "", string str4 = "", string str5 = "", string str6 = "", string str7 = "", string str8 = "", string str9 = "", string str10 = "")
    {
        hidecursor();
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int process = 0, keystroke, nCount = 0, counter = 0, i = 0;
        string Gmenu[10];

        str[0] = str1;
        str[1] = str2;
        str[2] = str3;
        str[3] = str4;
        str[4] = str5;
        str[5] = str6;
        str[6] = str7;
        str[7] = str8;
        str[8] = str9;
        str[9] = str10;

        for (int j = 0; i < 10; i++, j++)
        {
            if (str[i] == "")
                j--;
            else
                Gmenu[j] = str[i];
        }

        if (str1.size() != 0)
            nCount++;
        if (str2.size() != 0)
            nCount++;
        if (str3.size() != 0)
            nCount++;
        if (str4.size() != 0)
            nCount++;
        if (str5.size() != 0)
            nCount++;
        if (str6.size() != 0)
            nCount++;
        if (str7.size() != 0)
            nCount++;
        if (str8.size() != 0)
            nCount++;
        if (str9.size() != 0)
            nCount++;
        if (str10.size() != 0)
            nCount++;

        i = 0;

        if (m_clr == true)
            system("cls");

        while (true)
        {
            for (int j = 0; i <= 9; i++, j++)
            {

                m_gotoxy(m_x, m_y + i);
                if (i != process)
                {
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << Gmenu[i] << endl;
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, menu_color);
                    cout << Gmenu[i] << endl;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            }
            i = 0;
            keystroke = _getch();
            if (keystroke == Enter)
            {
                showcursor();
                for (int l = 0; l < 10; l++)
                    if (Gmenu[process] == str[l])
                        return l;
            }
            switch (keystroke)
            {
            case Down:
            {
                if (process < nCount - 1)
                {
                    process++;
                }
                break;
            }
            case Up:
            {
                if (process > 0)
                {
                    process--;
                }
                break;
            }
            }
        }
    }
};