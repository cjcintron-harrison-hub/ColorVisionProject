#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include<fstream>
using namespace std;


// Functions that reference each other
void DISPLAY_PALETTE(vector <string>&);
void ADD_COLOR(vector <string>&);


// Structure to hold a reference color, its RGB565 component values, and hexcode
struct ColorRef
{
  string name;
  int r; // 0 to 31
  int g; // 0 to 63
  int b; // 0 to 31
  string hexcode;
};

// Constant vector that holds all my colors
const vector <ColorRef> PALETTE =
{
  {"Black",            0,  0, 0, "#000000"},
  {"Dark Gray",        8, 16, 8, "#424142"},
  {"Gray",            16, 32, 16, "#848284"},
  {"Light Gray",      24, 48, 24, "#c5c2c5"},
  {"Brown",           16, 16, 0, "#844100"},
  {"Red",             31, 0, 0, "#ff0000"},
  {"Bright Orange",   31, 45, 0, "#ffb600"},
  {"Orange",          31, 35, 0, "#ff8e00"},
  {"Dull Orange",     25, 25, 5, "#ce6529"},
  {"Bright Yellow",   31, 63, 0, "#ffff00"},
  {"Yellow",          25, 50, 5, "#ceca29"},
  {"Bright Green",     0, 63, 0, "#00ff00"},
  {"Green",            5, 45, 5, "#2bb82b"},
  {"Sea Foam Green",  21, 52, 23, "#add7bd"},
  {"Persian Green",    0, 44, 16, "#02b386"},
  {"Midnight Green",   4, 16, 5, "#214129"},
  {"Cyan",             0, 63, 31, "#00ffff"},
  {"Light Blue",      15, 48, 30, "#7bc2f7"},
  {"Blue",             0, 0, 31, "#0000ff"},
  {"Dark Blue",        5, 10, 20, "#2928a5"},
  {"Purple",          16, 0, 20, "#8400a5"},
  {"Muted Purple",    13, 22, 18, "#6b5994"},
  {"Magenta",         31, 0, 31, "#ff00ff"},
  {"Pink",            31, 32, 20, "#ff82a5"},
  {"Light Pink",     31, 45, 25, "#ffb8cc"},
  {"White",           31, 63, 31, "#ffffff"}
    
};

const unordered_map<string, unordered_set<string>> FORBIDDEN_COLORS = 
{
  {"Black", {"Purple", "Dark Gray", "Brown", "Muted Purple", "Midnight Green", "Red", "Dark Blue"}},
  {"White", {"Bright Yellow", "Cyan", "Magenta", "Yellow", " Pink", "Light Pink"}},
  {"Red", {"Green", "Orange", "Dull Orange", "Brown", "Yellow", "Persian Green", "Bright Green", "Midnight Green", "Bright Orange", "Black"}},
  {"Green", {"Orange", "Dull Orange", "Brown", "Yellow", "Persian Green", "Red", "Bright Green", "Bright Orange", "Light Blue", "Dark Blue", "Blue"}},
  {"Blue", {"Muted Purple", "Dark Blue", "Green", "Light Blue", "Midnight Green", "Persian Green", "Magenta", "Purple"}},
  {"Bright Yellow", {"Bright Green", "Orange", "Bright Orange", "White", "Yellow"}},
  {"Cyan", {"White", "Light Blue", "Bright Green"}},
  {"Magenta", {"White", "Orange", "Pink", "Dull Orange", "Light Pink", "Bright Orange", "Blue", "Purple", "Dark Blue", "Light Blue"}},
  {"Orange", {"Red", "Green", "Yellow", "Persian Green", "Bright Green", "Bright Orange", "Magenta", "Light Pink"}},
  {"Gray", {"Persian Green", "Muted Purple", "Midnight Green", "Pink"}},
  {"Light Gray", {"Pink", "Light Pink", "Persian Green"}},
  {"Dark Gray", {"Black", "Midnight Green", "Persian Green", "Dark Blue"}},
  {"Purple", {"Black", "Dark Blue", "Blue", "Magenta", "Muted Purple", "Brown"}},
  {"Brown", {"Black", "Red", "Green", "Midnight Green", "Yellow", "Dull Orange", "Purple"}},
  {"Pink", {"Sea Foam Green", "Persian Green", "Light Gray", "White", "Light Pink", "Gray", "Bright Orange", "Magenta", "Yellow", "Dull Orange"}},
  {"Light Blue", {"Persian Green", "Green", "Sea Foam Green", "Bright Green", "Cyan", "Blue", "Magenta"}},
  {"Muted Purple", {"Black", "Purple", "Gray", "Dark Blue", "Blue", "Midnight Green"}},
  {"Midnight Green", {"Dark Gray", "Brown", "Gray", "Red", "Dark Blue", "Black", "Blue"}},
  {"Sea Foam Green", {"Persian Green", "Light Pink", "Pink"}},
  {"Yellow", {"White", "Orange", "Brown", "Dull Orange", "Green", "Red", "Light Pink", "Pink"}},
  {"Dull Orange", {"Yellow", "Magenta", "Red", "Bright Orange", "Light Pink", "Pink", "Brown", "Purple", "Orange", "Green", "Persian Green"}},
  {"Persian Green", {"Dull Orange", "Sea Foam Green", "Pink", "Green", "Bright Orange", "Gray", "Light Gray", "Dark Gray", "Red", "Orange", "Bright Green", "Blue", "Light Blue"}},
  {"Dark Blue", {"Purple", "Muted Purple", "Midnight Green", "Blue", "Green", "Black", "Dark Gray"}},
  {"Bright Green", {"Bright Yellow", "Bright Orange", "Orange", "Green", "Red", "Persian Green", "Cyan", "Light Blue"}},
  {"Bright Orange", {"Bright Green", "Persian Green", "Orange", "Green", "Dull Orange", "Pink", "Light Pink", "Magenta", "Red"}},
  {"Light Pink", {"White", "Bright Orange", "Dull Orange", "Yellow", "Pink", "Orange", "Magenta", "Bright Yellow", "Sea Foam Green", "Light Gray"}}
};

// Basic information about RGB565 for new users
void RGB565_INFO()
{
  cout << "\n";
  cout << "||To keep it simple this RGB565 uses 32 shades of red, 64 shades of green, and 32 shades of blue instead of 255 for each shade.||\n";
  cout << "||The format is similar to the standard RGB format except the range is smaller so it takes up less memory and representing only around 65,000 colors.||\n";
  cout << "||The R values go from a range of 0 to 31, G values from 0 to 63, and B values from 0 to 31.||\n";
  cout << "||All Black has a RGB of R:0, G:0, B:0 and all White has a RGB of R:31, G:63, B:31.||\n";
  cout << "||Now let's get to creating a palette that is color blind friendly!||\n";
}

// Identifies the closest color to the RGB values given
string identify_color(int r, int g, int b)
{
  string closest_name = "Unknown";
  string closest_hexcode = "Unknown";

  int min_distance = 99999; // Large baseline number for comparison

  for (const auto& color : PALETTE)
  {
    // R and B values get multiplied to keep all values consistent
    int distr = (r - color.r) * 2;
    int distg = (g - color.g);
    int distb = (b - color.b) * 2;

    // Calculate squared distance using basic int
    int distance = (distr * distr) + (distg * distg) + (distb * distb);

    // Keep track of the color with the shortest distance
    if (distance < min_distance)
    {
      min_distance = distance;
      closest_name = color.name;
    }
  }

  return closest_name;
}

// Identifies the closest hexcolor to the RGB values given
string identify_hex(int r, int g, int b)
{
  string closest_hexcode = "Unknown";

  int min_distance = 99999; // Large baseline number

  for (const auto& color : PALETTE)
  {
    // R and B values get multiplied to keep all values consistent
    int distr = (r - color.r) * 2;
    int distg = (g - color.g);
    int distb = (b - color.b) * 2;

    // Calculate squared distance using basic int
    int distance = (distr * distr) + (distg * distg) + (distb * distb);

    // Keep track of the color with the shortest distance
    if (distance < min_distance)
    {
      min_distance = distance;
      closest_hexcode = color.hexcode;
    }
  }

  return closest_hexcode;
}

// Let's the user control the pace
void CONTINUE()
{
  string user;
  cout << "||To continue type Y.|\n";
  cin >> user;
}

void CLEAR_SCREEN()
{
  // Print 100 newlines to push previous output out of view
  cout << string(100, '\n') << flush;
}

//Title Card
void TITLE()
{
    cout << R"(
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
    )" << "\n\n";
};

//Library Card
void MENU_LIBRARY()
{
    cout << R"(
    ==================================================================================
      ____ ___  _     ___  ____     ____  _     ___ _   _ ____  _   _ _____ ____ ____ 
     / ___/ _ \| |   / _ \|  _ \   | __ )| |   |_ _| \ | |  _ \| \ | | ____/ ___/ ___|
    | |  | | | | |  | | | | |_) |  |  _ \| |    | ||  \| | | | |  \| |  _| \___ \___ \
    | |__| |_| | |__| |_| |  _ <   | |_) | |___ | || |\  | |_| | |\  | |___ ___) |__) |
     \____\___/|_____\___/|_| \_\  |____/|_____|___|_| \_|____/|_| \_|_____|____/____/ 

     _     ___ ____  ____      _     ____  __   __
    | |   |_ _| __ )|  _ \    / \    | _ \ \ \ / /
    | |    | ||  _ \| |_) |  / _ \   | _) | \ V / 
    | |___ | || |_) |  _ <  / ___ \  | _ <   | |  
    |_____|___|____/|_| \_\/_/   \_\ |_| \_\ |_|  
    ==================================================================================
    )" << "\n";
}

//Menu
void MENU()
{
  cout << "||USE THE NUMPAD TO NAVIGATE THE MENU.||\n"
          "||REFER TO THE COLOR LIBRARY IF YOU HAVE TROUBLR FINDING THE COLOR YOU WANT.||\n";
  cout << "||1. DIPLAY MY COLOR PALETTE||\n";
  cout << "||2. ADD A COLOR TO MY PALETTE||\n";
  cout << "||3. RATE MY PALETTE||\n";
  cout << "||4. RANDOM COLOR GENERATOR||\n"
          "||5. COLOR LIBRARY||\n";
  cout << "||6. COLORBLINDNESS LIBRARY||\n"
          "||7. SAVE CURRENT PALETTE||\n"
          "||8. LOAD COLOR PALETTE||\n";
  cout << "||9. QUIT||\n\n";
}

//1. Display's the user's current color palette
void DISPLAY_PALETTE(vector<string>& user_palette)
{
  if(user_palette.size() > 0)
  {
    int i = 1;
    int user;
    int index;
    string exit;
    cout << "||CURRENT PALETTE||\n\n";

    for(auto& color : user_palette)
    {
      cout << i << ".) " << color << endl;
      i++;
    }
    cout << "\n";

    cout << "||Would you like to remove a color from your palette? Type the letter Y to remove a color.||\n"
            "||If you would like to return to the menu type any letter.||\n";
    cin >> exit;
    if((exit == "Y" || exit == "y") && (user_palette.size() > 0))
    {
      do
      {
        if((user_palette.size() == 0))
        {
          break;
        }
        CLEAR_SCREEN();
        cout << "||Okay. Enter the number of the color you would like to delete.||\n";
        int i = 1;
        for(auto& color : user_palette)
        {
          cout << i << ".) " << color << endl;
          i++;
        }
        cin >> user;
        index = user - 1;

        if((index < user_palette.size()) && (index > -1))
        {
          user_palette.erase(user_palette.begin() + index);
          cout << "||That color has been successfully removed. Would you like to remove another? Y/N||\n";
        }
        else
        {
          cout << "||That number was incorrect or your palette is empty. Would you like to try again? Y/N||\n";
        }

        cin >> exit;
        if((exit == "Y" || exit == "y") && (user_palette.size() == 0))
        {
          cout << "||Your color palette is already empty. There are no more colors to delete. You can return to the menu by typeing the letter N.||\n"
                  "||If you would like to go directly to the ADD COLORS page type the letter Y.||\n";
          cin >> exit;
          if((exit == "Y" || exit == "y"))
          {
            CLEAR_SCREEN();
            ADD_COLOR(user_palette);
            break;
          }
        }
      }while(exit != "N" && exit != "n");
    }
  }

  else
  {
    cout << "||Your palette is currently empty. Add some colors to it!||\n";
    CONTINUE();
  }
}

//2. Let's the user add a color to their color palette
void ADD_COLOR(vector<string>& user_palette)
{
  string user;
  int r, g, b;
  do
  {
    bool dupe = false;
    CLEAR_SCREEN();
    if(user_palette.size() == 5)
    {
      cout << "||Unfortunately you have 5 colors in your color palette which is the max. Please go to DISPLAY PALETTE to see your current color palette and remove a color.||\n";
      cout << "||Would you like to go to DISPLAY PALETTE now? Y/N||\n";
      cin >> user;
      if(user == "Y" || user == "y")
      {
        CLEAR_SCREEN();
        DISPLAY_PALETTE(user_palette);
        break;
      }
      else
      {
        CLEAR_SCREEN();
        break;
      }
    }

    else
    {
      cout << "||This program will have you create a palette of five colors and check if your palette is color blind friendly.||\n";
      cout << "Please enter your Red value (0-31): ";
      cin >> r;
      cout << "Please enter your Green value (0-63): ";
      cin >> g;
      cout << "Please enter your Blue value (0-31): ";
      cin >> b;

      if(r < 0 || r > 31 || g < 0 || g > 63 || b < 0 || b > 31)
      {
        cout << "||Error: Out of bounds. Valid RGB565 ranges are R: 0-31, G: 0-63, B: 0-31. Please try again.||\n";
      }

      else
      {
        cout << "||The closest color match is: " << identify_color(r, g, b) << "||\n";
        cout << "||The hexcode for the color is: " << identify_hex(r, g, b) << "||\n";
        cout << "||Would you like to add this color to your palette? Y/N||\n";
        string color = identify_color(r, g, b);
        cin >> user;

        if((user == "Y" || user == "y") && (user_palette.size() > 0))
        {
          for(size_t i = 0; i < user_palette.size(); i++)
          {
            if(color == user_palette[i])
            {
              dupe = true;
              cout << "This color is already in your palette so it cannot be added.\n";
              break;
            }

            else
            {
              dupe = false;
                
            }
          }

          if(dupe == false)
          {
            user_palette.push_back(color);
            cout << "||Great! The color has been added to your palette.||\n";
          
          }
        }
        
        else if((user == "Y" || user == "y"))
        {
          user_palette.push_back(color);
          cout << "||Great! The color has been added to your palette.||\n";
        }

        else
        {
          cout << "||Okay the color was discarded.||\n";
        }
      }
    }

    cout <<"||Would you like to return to the menu or add another color? Type the letter N to return to the menu or type the letter Y to add another color.||\n";
    cin >> user;
  }while(user != "N" && user != "n");
}

//3. Color Palette Evaluation

void EVALUATE(const vector<string>& user_palette)
{
  bool error = false;
  int num = 1;
  if(user_palette.size() > 1)
  {
    cout << "||YOUR PALETTE||\n\n";
    for(auto& color : user_palette)
    {
      cout << num << ".) " << color << endl;
      num++;
    }
    cout << "\n";
    for (size_t i = 0; i < user_palette.size(); ++i)
    {
      auto it = FORBIDDEN_COLORS.find(user_palette[i]);
      if (it == FORBIDDEN_COLORS.end()) continue;

      const auto& forbidden_set = it->second;
      for (size_t j = i + 1; j < user_palette.size(); ++j)
      {
        if (forbidden_set.count(user_palette[j]))
        {
          error = true;
          cout << "||Conflict found: " << user_palette[i] << " and " << user_palette[j] << " are hard for people with colorblindness to distingish.||\n";
        }
      }
    }

    if(error == false)
    {
        cout << "||Congratulations your palette of colors is colorblindness friendly. People with Deuteranopis, Trotanopia, and Protanopia would be able to distinguish your colors.||\n";
    }

  }

  else
  {
    cout << "||Your palette is currently empty or it doesnt have enough colors to be properly evaluated. Add some colors to it!||\n";
  }
  CONTINUE();
}

//4. Generates a random combination of RGB values and outputs the color
void RGB565_EX()
{
  cout << "||Generating Random Values||\n";
  // Define range
  int min = 0;
  int max = 31;
  int gmax = 63;

  // Initialize a random number generator
  random_device rd;
  mt19937 gen(rd());
  mt19937 genG(rd());
  uniform_int_distribution<> distrib(min, max);
  uniform_int_distribution<> distribG(min, gmax);

  // Generate random number in the range [min, max]
  int r = distrib(gen);
  int g = distribG(genG);
  int b = distrib(gen);
  cout << "||R = "<< r << " G = " << g << " B = " << b << "||\n";
  cout << "||The closest color match is: " << identify_color(r, g, b) << "||\n";
  cout << "||The hexcode for the color is: " << identify_hex(r, g, b) << "||\n";
}

//5. Color Library
void COLOR_2(const vector<ColorRef>&);

void COLOR_LIBRARY()
{
  COLOR_2(PALETTE);
}
void COLOR_2(const vector<ColorRef>& PALETTE)
{
    
  string user;
  do
  {
    cout << "||THIS IS THE LIST OF COLORS IN THE CURRENT LIBRARY||\n";
    cout << "||IF YOU WOULD LIKE TO SEE WHAT COLORS ARE NOT COMPATIBLE ENTER THE COLOR YOU WANT TO LOOK AT||\n";
    cout << "||TO RETURN TO MENU TYPE N||\n";
    cout << "{Color,   R,   G,   B,   HEXCODE}\n";
    for(const auto& color : PALETTE)
    {
      cout << "{" << color.name << ",  " << color.r << ", " << color.g << ", " << color.b << ",  " << color.hexcode << "}" << endl;
    }
    cin.ignore();
    getline(cin, user);
    auto it = FORBIDDEN_COLORS.find(user);
    if(it == FORBIDDEN_COLORS.end())
    {
      cout << "||Error. The color you entered couldn't be found because of misspelling or it simply doesn't exist.||\n"
              "||If you would like to try again type Y. To return to the menu type N.||\n";
      cin >> user;
    }
    else
    {
      CLEAR_SCREEN();
      cout << "||The color " << user << " shouldn't be paired with the following colors.||\n";
      const auto& forbidden_set = it->second;
      for (const auto& color : forbidden_set)
      {
          cout << "(" << color << ")" << endl;
      }
      cout << "||Would you like to look at another color? Type Y to try another color or to return to the menu type N.||\n";
      cin >> user;
      CLEAR_SCREEN();
    }
  }while(user != "n" && user != "N");
}

//6. Colorblindness Library
void PROTANOPIA()
{
  cout << "[1. WHAT IS IT?]\n";
  cout << "Protanopia is when the L-cones are completely absent. Like Deuteranopia, the person sees through only two cone types (M and S).\n"
          "Red-Green color discrimination is lost, but with an important additional effect: Reds can appear very dark, almost Black in extreme cases.\n"
          "This is because the L-cones are normally the primary detector of Red light — without them, Red wavelengths produce almost no signal.\n";

  cout << "\n[2. HOW RARE IS IT?]\n";
  cout << "Protonopia is the second most common form of color blindness sitting just behind Deuteranopia. Protanopia affects about 1.0% of males and 0.01% of females. Protanopia is most often inherited.\n";
  
  cout << "\n[3. HOW DOES IT AFFECT A PERSONS DAILY LIFE?]\n";
  cout << "Here are a few examples!\n\n";
                      
  cout << "Traffic lights can be difficult to interpret, particularly distinguishing red from amber signals.\n";

  cout << "Ripe red fruit like strawberries or cherries may be hard to spot among green foliage.\n";

  cout << "Color-coded charts, graphs, and maps in educational or professional settings can be unreadable.\n";

  cout << "Selecting clothing with coordinating colors is challenging, especially outfits involving reds, greens, or browns.\n";

  cout << "Cooking meat to the correct doneness can be difficult because the color change from raw to cooked is hard to see.\n";

  cout << "\n[4. HOW IS IT DIAGNOSED?]\n";
  cout << "The Ishihara color plate test is the most widely used screening tool and is effective at detecting Deuteranopia.\n";
  cout << "However the Ishihara test cannot distinguish between Deutan and Protan deficiencies on its own so additional testing would be required.\n\n";
  CONTINUE();
}

void DEUTERANOPIA()
{
  cout << "[1. WHAT IS IT?]\n";
  cout << "Deutranopia is when the M-cones are completely absent. The person has only two working cone types (L and S), so they see the world through a two-dimensional color space instead of three.\n"
          "The entire red-orange-yellow-green range collapses into varying shades of brownish-yellow. Blues and purples appear similar to each other.\n";

  cout << "\n[2. HOW RARE IS IT?]\n";
  cout << "Deutranopia is the most common out of all the types of color blindness affecting 1.2% of men and only about 0.01% of women.\n"
          "Deuteranopia is most commonly inherited rather then developed later in life.\n";

  cout << "\n[3. HOW DOES IT AFFECT A PERSONS DAILY LIFE?]\n";
  cout << "Here are a few examples!\n\n";
                      
  cout << "Distinguishing between green and red indicators on electronic devices, dashboards, and status lights is challenging.\n";

  cout << "Identifying the ripeness of fruit and vegetables such as bananas and tomatoes is often unreliable by color alone.\n";

  cout << "Reading color-coded subway or transit maps can be confusing when lines use red and green.\n";

  cout << "Nature-related activities like hiking or gardening may be affected because greens and browns blend together, making it harder to distinguish foliage from soil or bark.\n";

  cout<< "Interpreting color-coded data in charts, heat maps, or educational materials often requires additional context.\n";

  cout << "\n[4. HOW IS IT DIAGNOSED?]\n";
  cout << "The Ishihara color plate test is the most widely used screening tool and is effective at detecting deuteranopia.\n";
  cout << "However the Ishihara test cannot distinguish between Deutan and Protan deficiencies on its own so additional testing would be required.\n\n";
  CONTINUE();
}

void TRITANOPIA()
{
  cout << "[1. WHAT IS IT?]\n";
  cout << "Tritanopia is when the S-cones are completely absent. The person sees through only L and M cones, losing discrimination along the blue-yellow axis.\n"
          "Blues and greens become confused, yellows may appear pinkish or light gray, and the sky may look greenish. Purple is often indistinguishable from a dark reddish-brown.\n";

  cout << "\n[2. HOW RARE IS IT?]\n";
  cout << "Tritanopia approximatly affects approximately 1 in 30,000-50,000 people making it one of the most rare forms of colorb lindness outside of complete color blindness.\n"
          "Unlike Protanopia and Deuteranopia, Tritanopia is most oftnely aquired rather than inherited.\n";

  cout << "\n[3. HOW DOES IT AFFECT A PERSONS DAILY LIFE?]\n";
  cout << "Here are a few examples!\n\n";

  cout << "Distinguishing between blue and green objects, such as blue and green road signs or clothing, is often unreliable.\n";

  cout << "Yellow safety markings and warning signs may blend with white or light gray backgrounds.\n";

  cout << "Selecting matching clothing is difficult when outfits involve blues, greens, or purples.\n";

  cout << "Working with digital interfaces that use blue and yellow highlighting for warnings or selections can be confusing.\n";

  cout << "Appreciating sunsets, blue skies, and other natural color phenomena may be diminished because the blue and yellow components are reduced.\n";

  cout << "\n[4. HOW IS IT DIAGNOSED?]\n";
  cout << "Tritanopia is more often acquired (from disease, medication, or aging) than inherited.\n"
          "Conditions that can cause acquired tritanopia include diabetic retinopathy, glaucoma, age-related macular degeneration, and exposure to certain industrial solvents.\n";
  cout << "Standard Ishihara color plates are designed to detect Red-Green deficiency and typically miss Tritanopia meaning specialized tests are required in order for a proper diagnosis.\n\n";
  CONTINUE();
}

void LIBRARY()
{
  string user;
  do
  {
    MENU_LIBRARY();
    cout << "||THIS IS A SMALL LIBRARY ON THE THREE MAJOR TYPES OF COLORBLINDESS.||\n";
    cout << "||PLEASE USE THE NUMPAD TO NAVIGATE THE MENU||\n";
    cout << "||1. PROTANOPIA||\n";
    cout << "||2. DEUTERANOPIA||\n";
    cout << "||3. TRITANOPIA||\n";
    cout << "||4. QUIT||\n";
    cin >> user;

    if(user == "1")
    {
      CLEAR_SCREEN();
      PROTANOPIA();
    }

    else if(user == "2")
    {
      CLEAR_SCREEN();
      DEUTERANOPIA();
    }

    else if(user == "3")
    {
      CLEAR_SCREEN();
      TRITANOPIA();
    }
    CLEAR_SCREEN();
  }while(user != "4");
}

//7. Save current color palette
void SAVE(vector<string>& user_palette)
{
  string file_name;
  string user;
  int i = 1;
  ofstream saveFS;

  if (user_palette.empty())
  {
    CLEAR_SCREEN();
    cout << "||Your palette is currently empty. Nothing to save.||\n";
    CONTINUE();
    return;
  }

  do
  {
    CLEAR_SCREEN();
    cout << "||CURRENT PALETTE||\n\n";
    for(auto& color : user_palette)
    {
        cout << i << ".) " << color << endl;
        i++;
    }
    cout << "\n";
    cout << "||What would you like to name the file you are saving to?||\n";
    cin >> file_name;

    saveFS.clear();
    saveFS.open(file_name);

    if (!saveFS.is_open())
    {
      cerr << "||Error. Could not create or open file.||\n";
      cout << "||To return to the menu type N. To try again type Y.||\n";
      cin >> user;
    }
    else
    {
      for (size_t i = 0; i < user_palette.size(); ++i)
      {
        saveFS << user_palette[i] << '\n';
        cout << "||Color " << user_palette[i] << " was successfully saved.||\n";
      }

      saveFS.close();
      cout << "||Palette saved to " << file_name << ".||\n";
      cout << "||To return to the menu type N. To save to another file type Y.||\n";
      cin >> user;
    }
  } while (user != "N" && user != "n");
}

//8. Load saved color palettes
void LOAD(vector<string>& user_palette)
{
  string file_name;
  string data;
  string user;
  ifstream loadFS;
  do
  {
    CLEAR_SCREEN();
    cout << "||When loading a file ensure that all your colors are capitalized or formated like the example.||\n";
    cout << "{EX: Blue, Red, Green, Light Blue}\n"
            "or\n"
            "{Blue\n Red\n Green\n Light Blue}\n";
    cout << "||What is the name of the file you are trying to load?||\n";
    cin >> file_name;
    loadFS.open(file_name);
    loadFS.clear();

    if(!loadFS.is_open())
    {
      cerr << "||Error. Could not open file.||\n";
      cout << "||To return to the menu type N. To try again tyoe Y.||\n";
      cin >> user;
    }

    else
    {
      while(getline(loadFS, data))
      {
        while (!data.empty() && (data.back() == '\r' || data.back() == ' ' || data.back() == '\t'))
        {
          data.pop_back();
        }

        if (data.empty()) continue;

        auto it = FORBIDDEN_COLORS.find(data);
        if((it == FORBIDDEN_COLORS.end()) || (user_palette.size() == 5))
        {
          cout << "||Error. " << data << " could not be added because it is not in our data base or because your palette is already full.||\n";
        }

        else
        {
          user_palette.push_back(data);
          cout << "||Color " << data << " was successfully loaded.||\n";
        }
      }
      loadFS.close();
      cout << "||To return to the menu type N. To try again type Y.||\n";
      cin >> user;
    }
  }while(user != "N" && user != "n");
}