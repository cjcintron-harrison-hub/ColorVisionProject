#include <iostream>
using namespace std;

int main()
{
    char x = 'y';
    int color1=0;
    int color2=0;
    int Colorblindness=0;
    int Tritanopia=0;
    int Protanopia=0;
    int Deuteranopia=0;

    cout << "Color Combination Tester!\n\n";

    do{
        cout << "Using the numpad please select a color listed below or Back.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Blue.\n";
        cout << "4. Purple.\n";
        cout << "5. Yellow.\n";
        cout << "6. Pink.\n";
        cout << "7. Orange.\n";
        cout << "8. Brown.\n";
        cout << "9. Quit.\n";
        cin >> color1;
        cout << "\n";

     switch(color1){
        case 1: cout << "The color Red cannot be seen by people with Protanopia, which is Red blindness, and people with Deuteranopia, which is Green blindness, can see the color Red but cannot distinguish it from other specific colors.\n\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Green.\n";
        cout << "2. Blue.\n";
        cout << "3. Purple.\n";
        cout << "4. Yellow.\n";
        cout << "5. Pink.\n";
        cout << "6. Orange.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

            switch(color2){
                case 1: cout << "Red and Green is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n";
                break;

                case 2: cout << "Red and Blue is perfectly acceptable as a color combination for people with color blindness.\n\n";
                break;

                case 3: cout << "Red and Purple is an acceptable color combination for people with color blindness.\n\n";
                break;

                case 4: cout << "Red and Yellow can be tricky for people with Protanopia and Deuteranopia color blindness depending on the hue and contrast. I wouldn't recommend this combination of colors as colorblind friendly.\n\n";
                break;

                case 5: cout << "Red and Pink is a poor color combination. People with Protanopia, Deuteranopia, and Tritanopia can struggle with differentiating the two.\n\n";
                break;

                case 6: cout << "Red and Orange is a poor color combination. People with Protanopia and Deuteranopia can struggle with differentiating the two.\n\n";
                break;

                case 7: cout << "Red and Brown is a poor color combination. People with Protanopia and Deuteranopia will struggle with differentiating between the two.\n\n";
                break;

                case 8: cout << "\n\n";
                break;

                default: cout<< "Invalid input.\n\n";
                break;
            }
        break;

        case 2: cout << "The color Green cannot be seen by people with Deuteranopia, which is Green blindness, and people with Protanopia, which is Red blindness, can see the color Green but cannot easily distinguish the color from specific colors.\n\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Blue.\n";
        cout << "3. Purple.\n";
        cout << "4. Yellow.\n";
        cout << "5. Pink.\n";
        cout << "6. Orange.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";
        
        switch(color2){
        case 1: cout << "Green and Red is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

        case 2: cout << "Green and Blue is a poor color combination. People with Tritanopia will not be able to differentiate between the two colors.\n\n"; break;

        case 3: cout << "Green and Purple is a poor color combination. People with Protanopia could struggle to distingish these colors depending on the hue.\n\n"; break;

        case 4: cout << "Green and Yellow is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

        case 5: cout << "Green and Pink is a poor color combination. People with Deuteranopia could struggle to distingish these colors depending on the hue.\n\n"; break;

        case 6: cout << "Green and Orange is a poor color combination. People with Deuteranopia and Protanopia could struggle to distingish these colors depending on the hue.\n\n"; break;

        case 7: cout << "Green and Brown is a poor color combination. People with Deuteranopia and Protanopia could struggle to distingish these colors depending on the hue. \n\n"; break;

        case 8: cout << "\n\n"; break;

        default: cout << "Invalid input.\n\n"; break;
        
     }
        break;

        case 3: cout << "The color Blue cannot be seen by people with Tritanopia, which is Blue-Yellow blindness. The Blue color shifts to either Teal or Green instead of being actually Blue.\n\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Purple.\n";
        cout << "4. Yellow.\n";
        cout << "5. Pink.\n";
        cout << "6. Orange.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

        switch(color2){
            case 1: cout << "Blue and Red is perfectly acceptable as a color combination for people with color blindness.\n\n"; break;

            case 2: cout << "Blue and Green is a poor color combination. People with Tritanopia will not be able to differentiate between the two colors.\n\n"; break;

            case 3: cout << "Blue and Purple is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 4: cout << "Blue and Yellow is perfectly acceptable as a color combination for people with color blindness. However for people with extreme cases of Tritanopia it can be difficult.\n\n"; break;

            case 5: cout << "Blue and Pink is perfectly acceptable as a color combination for people with color blindness.\n\n"; break;

            case 6: cout << "Blue and Orange is considered the best combination of colors that can be used for all types of color blindness. This is the best possible combination.\n\n"; break;

            case 7: cout << "Blue and Brown is perfectly acceptable as a color combination for people with color blindness.\n\n"; break;

            case 8: cout << "\n\n"; break;

            default: cout << "Invalid input.\n\n"; break;
     }
        break;

        case 4: cout << "The color Purple can be seen by people with Protanopia, which is Red blindness, Deuteranopia, which is Green blindness, and Tritanopia, which is Blue-Yellow blindness.\n\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Blue.\n";
        cout << "4. Yellow.\n";
        cout << "5. Pink.\n";
        cout << "6. Orange.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

        switch(color2){
            case 1: cout << "Purple and Red is an acceptable color combination for people with color blindness.\n\n"; break;

            case 2: cout << "Purple and Green is a poor color combination. People with Protanopia could struggle to distingish these colors depending on the hue.\n\n"; break;

            case 3: cout << "Purple and Blue is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 4: cout << "Purple and Yellow is a poor color combination. People with Tritanopia will strugggle to distinguish the two colors.\n\n"; break;

            case 5: cout << "Purple and Pink is a poor color combination. People with Protanopia, Deuteranopia, and Tritanopia can struggle with differentiating the two.\n\n"; break;

            case 6: cout << "Purple and Orange is an acceptable color combination for people with color blindness and is considered one of the best color combinations for color blindness.\n\n"; break;

            case 7: cout << "Purple and Brown is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors depending on the hue.\n\n"; break;

            case 8: cout << "\n\n"; break;

            default: cout << "Invalid input.\n\n"; break;
     }
        break;

        case 5: cout << "The color Yellow cannot be seen by people with Tritanopia, which is Blue-Yellow blindness.\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Blue.\n";
        cout << "4. Purple.\n";
        cout << "5. Pink.\n";
        cout << "6. Orange.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

        switch(color2){
            case 1: cout << "Yellow and Red can be tricky for people with Protanopia and Deuteranopia color blindness depending on the hue and contrast. I wouldn't recommend this combination of colors as colorblind friendly.\n\n"; break;

            case 2: cout << "Yellow and Green is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 3: cout << "Yellow and Blue is mostly acceptable as a color combination for people with color blindness. However for people with extreme cases of Tritanopia it can be difficult.\n\n"; break;

            case 4: cout << "Yellow and Purple is a poor color combination. People with Tritanopia will strugggle to distinguish the two colors.\n\n"; break;

            case 5: cout << "Yellow and Pink is a poor color combination. People with Tritanopia will strugggle to distinguish the two colors.\n\n"; break;

            case 6: cout << "Yellow and Orange is a poor color combination. People with Protanopia, Deuteranopia, and Tritanopia can struggle with differentiating the two.\n\n"; break;

            case 7: cout << "Yellow and Brown is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 8: cout << "\n\n"; break;

            default: cout << "Invalid input.\n\n"; break;
     }
        break;

        case 6: cout << "The color Pink can be perceived by people with Protanopia, which is Red blindness, Deuteranopia, which is Green blindness, and Tritanopia, which is Blue-Yellow blindness although the perception can be altered.\n\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Blue.\n";
        cout << "4. Purple.\n";
        cout << "5. Yellow.\n";
        cout << "6. Orange.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

        switch(color2){
            case 1: cout << "Pink and Red is a poor color combination. People with Protanopia, Deuteranopia, and Tritanopia can struggle with differentiating the two.\n\n"; break;

            case 2: cout << "Pink and Green is a poor color combination. People with Deuteranopia could struggle to distingish these colors depending on the hue.\n\n"; break;

            case 3: cout << "Pink and Blue is perfectly acceptable as a color combination for people with color blindness.\n\n"; break;

            case 4: cout << "Pink and Purple is a poor color combination. People with Protanopia, Deuteranopia, and Tritanopia can struggle with differentiating the two.\n\n"; break;

            case 5: cout << "Pink and Yellow is a poor color combination. People with Tritanopia will strugggle to distinguish the two colors.\n\n"; break;

            case 6: cout << "Pink and Orange can potentially be difficult to distinguish for people with Protonopia and Deuteranopia. As long as you avoid lighter tones though it could potentially work.\n\n"; break;

            case 7: cout << "Pink and Brown is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 8: cout << "\n\n"; break;

            default: cout << "Invalid input.\n\n"; break;
     }
        break;

        case 7: cout << "The color Orange is recognizable by people with Protanopia, which is Red blindness, Deuteranopia, which is Green blindness, and Tritanopia, which is Blue-Yellow blindness. The appearance however is still altered even though it's recognizable.\n\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Blue.\n";
        cout << "4. Purple.\n";
        cout << "5. Yellow.\n";
        cout << "6. Pink.\n";
        cout << "7. Brown.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

        switch(color2){
            case 1: cout << "Orange and Red is a poor color combination. People with Protanopia and Deuteranopia can struggle with differentiating the two.\n\n"; break;

            case 2: cout << "Orange and Green is a poor color combination. People with Deuteranopia and Protanopia could struggle to distingish these colors depending on the hue.\n\n"; break;

            case 3: cout << "Orange and Blue is considered the best combination of colors that can be used for all types of color blindness. This is the best possible combination.\n\n"; break;

            case 4: cout << "Orange and Purple is an acceptable color combination for people with color blindness and is considered one of the best color combinations for color blindness.\n\n"; break;

            case 5: cout << "Orange and Yellow is a poor color combination. People with Protanopia, Deuteranopia, and Tritanopia can struggle with differentiating the two.\n\n"; break;

            case 6: cout << "Orange and Pink can potentially be difficult to distinguish for people with Protonopia and Deuteranopia. As long as you avoid lighter tones though it could potentially work.\n\n"; break;

            case 7: cout << "Orange and Brown is a poor color combination. People with Protanopia and Deuteranopia can struggle with differentiating the two.\n\n"; break;

            case 8: cout << "\n\n"; break;

            default: cout << "Invalid input.\n\n"; break;
     }
        break;

        case 8: cout << "The Brown is recognizable to people with Protanopia, which is Red blindness, Deuteranopia, which is Green blindness, and Tritanopia, which is Blue-Yellow blindness.\n";
        cout << "Using the numpad please select a second color listed below.\n";
        cout << "1. Red.\n";
        cout << "2. Green.\n";
        cout << "3. Blue.\n";
        cout << "4. Purple.\n";
        cout << "5. Yellow.\n";
        cout << "6. Pink.\n";
        cout << "7. Orange.\n";
        cout << "8. Back.\n";
        cin >> color2;
        cout << "\n";

        switch(color2){
            case 1: cout << "Brown and Red is a poor color combination. People with Protanopia and Deuteranopia will struggle with differentiating between the two.\n\n"; break;

            case 2: cout << "Brown and Green is a poor color combination. People with Deuteranopia and Protanopia could struggle to distingish these colors depending on the hue.\n\n"; break;

            case 3: cout << "Brown and Blue is perfectly acceptable as a color combination for people with color blindness.\n\n"; break;

            case 4: cout << "Brown and Purple is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors depending on the hue.\n\n"; break;

            case 5: cout << "Brown and Yellow is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 6: cout << "Brown and Pink is a poor color combination. People with Deuteranopia and Protanopia will not be able to easily distingish these colors.\n\n"; break;

            case 7: cout << "Brown and Orange is a poor color combination. People with Protanopia and Deuteranopia can struggle with differentiating the two.\n\n"; break;

            case 8: cout << "\n\n"; break;

            default: cout << "Invalid input.\n\n"; break;
     }
        break;

        case 9: cout << "\n\n";
        break;

        default: cout << "Invalid input.\n\n";
     }


    }
     while(color1!=9);
        
        
    cout << "Before you go would you like to learn more about Color blindness? y/n. \n";
    cin >> x;
    cout << "\n";

    if(x == 'y'){
        cout << "Great!";
        do{
            cout << "\nWhich type of color blindness would you like to learn more about? Please input your answer using the numpad. If you want to exit hit 4.\n";
            cout << "1. Tritanopia.\n";
            cout << "2. Deuteranopia.\n";
            cout << "3. Protanopia.\n";
            cout << "4. Quit.\n";
            cin >> Colorblindness;
            cout << "\n";
            
            switch(Colorblindness){
                case 1: cout << "You have selected Tritanopia! What would you like to learn?\n";
                cout << "1. What is it?\n";
                cout << "2. How rare is it?\n";
                cout << "3. How does it affect a persons daily life?\n";
                cout << "4. How is it diagnosed?\n";
                cout << "5. Back.\n";
                cin >> Tritanopia;
                cout << "\n";

                    switch(Tritanopia){
                        case 1: cout << "Tritanopia is when the S-cones are completely absent. The person sees through only L and M cones, losing discrimination along the blue-yellow axis. Blues and greens become confused, yellows may appear pinkish or light gray, and the sky may look greenish. Purple is often indistinguishable from a dark reddish-brown.\n";
                        break;

                        case 2: cout << "Tritanopia approximatly affects approximately 1 in 30,000-50,000 people making it one of the most rare forms of colorb lindness outside of complete color blindness. Unlike Protanopia and Deuteranopia, Tritanopia is most oftnely aquired rather than inherited.\n";
                        break;

                        case 3: cout << "Here are a few examples!\n\n";

                        cout << "Distinguishing between blue and green objects, such as blue and green road signs or clothing, is often unreliable.\n";

                        cout << "Yellow safety markings and warning signs may blend with white or light gray backgrounds.\n";

                        cout << "Selecting matching clothing is difficult when outfits involve blues, greens, or purples.\n";

                        cout << "Working with digital interfaces that use blue and yellow highlighting for warnings or selections can be confusing.\n";

                        cout << "Appreciating sunsets, blue skies, and other natural color phenomena may be diminished because the blue and yellow components are reduced.\n";
                        break;

                        case 4: cout << "Tritanopia is more often acquired (from disease, medication, or aging) than inherited. Conditions that can cause acquired tritanopia include diabetic retinopathy, glaucoma, age-related macular degeneration, and exposure to certain industrial solvents.\n";
                        cout << "Standard Ishihara color plates are designed to detect Red-Green deficiency and typically miss Tritanopia meaning specialized tests are required in order for a proper diagnosis.\n";
                        break;

                        case 5: cout << "\n\n";
                        break;

                        default: cout << "Unkown Prompt.\n";
                        break;
                    }
                break;

                case 2: cout << "You have selected Deuteranopia! What would you like to learn?\n";
                cout << "1. What is Deuteranopia?\n";
                cout << "2. How rare is it?\n";
                cout << "3. How does it affect a persons daily life?\n";
                cout << "4. How is it diagnosed?\n";
                cout << "5. Back.\n";
                cin >> Deuteranopia;
                cout << "\n";

                    switch(Deuteranopia){
                        case 1: cout << "Deutranopia is when the M-cones are completely absent. The person has only two working cone types (L and S), so they see the world through a two-dimensional color space instead of three. The entire red-orange-yellow-green range collapses into varying shades of brownish-yellow. Blues and purples appear similar to each other.\n";
                        break;

                        case 2: cout << "Deutranopia is the most common out of all the types of color blindness affecting 1.2% of men and only about 0.01% of women. Deuteranopia is most commonly inherited rather then developed later in life.\n";
                        break;

                        case 3: cout << "Here are a few examples!\n\n";
                        
                        cout << "Distinguishing between green and red indicators on electronic devices, dashboards, and status lights is challenging.\n";

                        cout << "Identifying the ripeness of fruit and vegetables such as bananas and tomatoes is often unreliable by color alone.\n";

                        cout << "Reading color-coded subway or transit maps can be confusing when lines use red and green.\n";

                        cout << "Nature-related activities like hiking or gardening may be affected because greens and browns blend together, making it harder to distinguish foliage from soil or bark.\n";

                        cout<< "Interpreting color-coded data in charts, heat maps, or educational materials often requires additional context.\n";
                        break;

                        case 4: cout << "The Ishihara color plate test is the most widely used screening tool and is effective at detecting deuteranopia.\n";
                        cout << "However the Ishihara test cannot distinguish between Deutan and Protan deficiencies on its own so additional testing would be required.\n";
                        break;

                        case 5: cout << "\n\n";
                        break;

                        default: cout << "Unkown Prompt.\n";
                        break;
                    }
                break;

                case 3: cout << "You have selected Pritanopia! What would you like to learn?\n";
                cout << "1. What is Pritanopia?\n";
                cout << "2. How rare is it?\n";
                cout << "3. How does it affect a persons daily life?\n";
                cout << "4. How is it diagnosed?\n";
                cout << "5. Back.\n";
                cin >> Protanopia;
                cout << "\n";

                    switch(Protanopia){
                        case 1: cout << "Protanopia is when the L-cones are completely absent. Like Deuteranopia, the person sees through only two cone types (M and S). Red-Green discrimination is lost, but with an important additional effect: Reds appear very dark, almost Black. This is because the L-cones are normally the primary detector of Red light — without them, Red wavelengths produce almost no signal.\n";
                        break;

                        case 2: cout << "Protonopia is the second most common form of color blindness sitting just behind Deuteranopia. Protanopia affects about 1.0% of males and 0.01% of females. Protanopia is most often inherited.\n";
                        break;

                        case 3: cout << "Here are a few examples!\n\n";
                        
                        cout << "Traffic lights can be difficult to interpret, particularly distinguishing red from amber signals.\n";

                        cout << "Ripe red fruit like strawberries or cherries may be hard to spot among green foliage.\n";

                        cout << "Color-coded charts, graphs, and maps in educational or professional settings can be unreadable.\n";

                        cout << "Selecting clothing with coordinating colors is challenging, especially outfits involving reds, greens, or browns.\n";

                        cout << "Cooking meat to the correct doneness can be difficult because the color change from raw to cooked is hard to see.\n";
                        break;

                        case 4: cout << "The Ishihara color plate test is the most widely used screening tool and is effective at detecting Deuteranopia.\n";
                        cout << "However the Ishihara test cannot distinguish between Deutan and Protan deficiencies on its own so additional testing would be required.\n";
                        break;

                        case 5: cout << "\n\n";
                        break;

                        default: cout << "Unkown Prompt.\n";
                        break;
                    }
                break;
                default: cout << "Goodbye!";
            }
        }
        while(Colorblindness!=4);
    }

    else{
        cout << "Goodbye!\n";
    }
    
  return 0;
}
