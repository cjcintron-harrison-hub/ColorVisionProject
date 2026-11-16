#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

// Functions
string identify_color(int r , int g, int b);
string identify_hex(int r, int g, int b);
void CLEAR_SCREEN();
void CONTINUE();
void RGB565_INFO();
void TITLE();
void MENU();
void DISPLAY_PALETTE(vector <string>&);
void ADD_COLOR(vector <string>&);
void EVALUATE(const vector<string>&);
void RGB565_EX();
void COLOR_LIBRARY();
void LIBRARY();
void MENU_LIBRARY();
void PROTANOPIA();
void DEUTERANOPIA();
void TRITANOPIA();
void SAVE(vector <string>&);
void LOAD(vector <string>&);


int main()
{
    int r = 0, g = 0, b = 0;
    string user_input;
    ofstream out_FS;
    ifstream in_FS;
    identify_color(r, g, b);
    identify_hex(r, g, b);
    vector <string> user_palette;
    

    cout << "||Welcome!||\n";
    cout << "||This is a program designed to help you create a color blind friendly pallet.||\n";
    cout << "||This program uses a RGB565 color format which is also know as 16-bit RGB.||\n";
    cout << "||Are you familiar with this color format? Y/N.||\n";
    do
    {
        cin >> user_input;
        if ((user_input == "y") || (user_input == "Y"))
        {
            cout << "||Great!||\n";
        }
        
        else if ((user_input == "n") || (user_input == "N"))
        {
            CLEAR_SCREEN();
            RGB565_INFO();
        }
        
        else
        {
            cout << "||Sorry I think you typed the wrong thing, can you try again?||\n\n";
        }
    }while(user_input != "y" && user_input != "Y" && user_input != "n" && user_input != "N");
    cout << "||To get to the menu type anything and hit enter to begin.||\n";
    cin.ignore();
    getline(cin, user_input);
    CLEAR_SCREEN();
    
    do
    {
        TITLE();
        MENU();
        
        cin >> user_input;
        if(user_input == "1")
        {
            CLEAR_SCREEN();
            DISPLAY_PALETTE(user_palette);
            CLEAR_SCREEN();
        }
        else if(user_input == "2")
        {
            ADD_COLOR(user_palette);
            CLEAR_SCREEN();
        }
        else if(user_input == "3")
        {
            CLEAR_SCREEN();
            EVALUATE(user_palette);
            CLEAR_SCREEN();
        }
        else if(user_input == "4")
        {
            CLEAR_SCREEN();
            RGB565_EX();
            CONTINUE();
            CLEAR_SCREEN();
        }
        else if(user_input == "5")
        {
            CLEAR_SCREEN();
            COLOR_LIBRARY();
            CLEAR_SCREEN();
        }
        else if(user_input == "6")
        {
            CLEAR_SCREEN();
            LIBRARY();
        }
        else if(user_input == "7")
        {
            CLEAR_SCREEN();
            SAVE(user_palette);
            CLEAR_SCREEN();
        }
        else if(user_input == "8")
        {
            LOAD(user_palette);
            CLEAR_SCREEN();
        }
    }while(user_input != "9");
}