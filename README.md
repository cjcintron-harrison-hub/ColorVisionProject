# Color Blindness Color Combination Finder

## Description

**version 2.0**

My program has been updated to use RGB565 values to help users create or load a color palette of up to a max of five colors and then have it evaluated to see if any colors conflict with each other and determine if it's colorblind friendly.

## Developer

Cameryn Cintron-Harrison

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
=========================================================================================
  ____ ___  _     ___  ____         ____  _     ___ _   _ ____  _   _ _____ ____ ____ 
 / ___/ _ \| |   / _ \|  _ \       | __ )| |   |_ _| \ | |  _ \| \ | | ____/ ___/ ___|
| |  | | | | |  | | | | |_) |      |  _ \| |    | ||  \| | | | |  \| |  _| \___ \___ \
| |__| |_| | |__| |_| |  _ <       | |_) | |___ | || |\  | |_| | |\  | |___ ___) |__) |
 \____\___/|_____\___/|_| \_\      |____/|_____|___|_| \_|____/|_| \_|_____|____/____/ 

 ____   _   __     _____ _____ _____ _____       ____ ____  _____    _ _____ ___  ____  
|  _ \ / \  | |   | ____|_   _|_   _| ____|     / ___|  _ \| ____|  / \_   _/ _ \|  _ \ 
| |_) / _ \ | |   |  _|   | |   | | |  _|      | |   | |_) |  _|   / _ \| || | | | |_) |
|  __/ ___ \| |___| |___  | |   | | | |___     | |___|  _ <| |___ / ___ \ || |_| |  _ < 
|_| /_/   \_\_____|_____| |_|   |_| |_____|     \____|_| \_\_____/_/   \_\_|\___/|_| \_\
=========================================================================================
    

||USE THE NUMPAD TO NAVIGATE THE MENU.||
||REFER TO THE COLOR LIBRARY IF YOU HAVE TROUBLR FINDING THE COLOR YOU WANT.||
||1. DIPLAY MY COLOR PALETTE||
||2. ADD A COLOR TO MY PALETTE||
||3. RATE MY PALETTE||
||4. RANDOM COLOR GENERATOR||
||5. COLOR LIBRARY||
||6. COLORBLINDNESS LIBRARY||
||7. SAVE CURRENT PALETTE||
||8. LOAD COLOR PALETTE||
||9. QUIT||
___________________________________________________________________________________________________________________

||This program will have you create a palette of five colors and check if your palette is color blind friendly.||
Please enter your Red value (0-31): 23
Please enter your Green value (0-63): 12
Please enter your Blue value (0-31): 31
||The closest color match is: Magenta||
||The hexcode for the color is: #ff00ff||
||Would you like to add this color to your palette? Y/N||
y
||Great! The color has been added to your palette.||
||Would you like to return to the menu or add another color? Type the letter N to return to the menu or type the letter Y to add another color.||

___________________________________________________________________________________________________________________

||CURRENT PALETTE||

1.) Dark Gray
2.) Red
3.) Green
4.) Light Blue

||Would you like to remove a color from your palette? Type the letter Y to remove a color.||
||If you would like to return to the menu type any letter.||

___________________________________________________________________________________________________________________

||YOUR PALETTE||

1.) Dark Gray
2.) Red
3.) Green
4.) Light Blue

||Conflict found: Red and Green are hard for people with colorblindness to distingish.||
||Conflict found: Green and Light Blue are hard for people with colorblindness to distingish.||
||To continue type Y.|

___________________________________________________________________________________________________________________

||CURRENT PALETTE||

1.) Dark Gray
2.) Red
3.) Green
4.) Light Blue

||What would you like to name the file you are saving to?||
color
||Color Dark Gray was successfully saved.||
||Color Red was successfully saved.||
||Color Green was successfully saved.||
||Color Light Blue was successfully saved.||
||Palette saved to color.||
||To return to the menu type N. To save to another file type Y.||

___________________________________________________________________________________________________________________

||When loading a file ensure that all your colors are capitalized or formated like the example.||
{EX: Blue, Red, Green, Light Blue}
or
{Blue
 Red
 Green
 Light Blue}
||What is the name of the file you are trying to load?||
color
||Color Dark Gray was successfully loaded.||
||Color Red was successfully loaded.||
||Color Green was successfully loaded.||
||Color Light Blue was successfully loaded.||
||To return to the menu type N. To try again type Y.||