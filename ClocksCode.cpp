/*
 * ClocksCode.cpp
 *
 *  Date: 2025-05-25
 *  Author: Scott Weiss
 */

#include <iostream> //Included to be able to input and output data.
#include <iomanip> //Included to use various manipulators in the program.
using namespace std;

void clockDisplay(int userTime, int userMenuEntry) //Function to display the clocks.
{
    int timePlaceholder = userTime; //Declare place holder to avoid making changes to userTime.
    int seconds = timePlaceholder % 100; //Initialize the seconds.
    timePlaceholder = timePlaceholder / 100; 
    int minutes = timePlaceholder % 100; //Initialize the minutes.
    timePlaceholder = timePlaceholder / 100;
    int hours = timePlaceholder; //Initialize the hours.
    
    if (userMenuEntry == 1) //If the user input the menu entry to change the hours.
    {
        cout << setw(25) << setfill('*') << "";
        cout << setw(5) << setfill(' ') << "";
        cout << setw(25) << setfill('*') << "";
        cout << endl; //Set top row of boxes used for the clock displays.

        cout << "*     12-Hour Clock     *" << "";
        cout << setw(5) << setfill(' ') << "";
        cout << "*     24-Hour Clock     *" << "";
        cout << endl; //Set next line of clock displays.

        cout << "*      " << ""; //Setting the 12-Hour Clock display time.
        if ( (hours > 0)  && (hours < 10) ) { //If the hours is a single digit, add a zero in front of it.
            cout << "0" << hours << ":";
        }
        else if ( (hours >= 10) && (hours <= 12) ) { //If a double digit, display as normal.
            cout << hours << ":";
        }
        else if ( hours == 0 ) //Using 24-hour format to determine if it's midnight, to display double zeroes.
        { 
            cout << "12:";
        }
        else if ((hours - 12) >= 10 && (hours - 12) <= 12) //If the time is late evening to display without an extra zero and by itself.
        { 
            cout << (hours - 12) << ":"; 
        }
        else //ELSE display the time with a zero in front of the single digit hour.
        {
            cout << "0" << (hours - 12) << ":";
        }

        if (minutes < 10) //If a single digit minute, display an extra zero in front of it.
        {
            cout << "0" << minutes << ":";
        }
        else //ELSE display the minutes as normal.
        {
            cout << minutes << ":";
        }

        if (seconds < 10) //If a single digit second, display an extra zero in front of it.
        {
            cout << "0" << seconds << " ";
        }
        else //ELSE display the seconds as normal.
        {
            cout << seconds << " ";
        }

        if ((hours-12) >= 0) //Using 24-hour number to determine if time is in second half of the day to use "PM".
        {                   
            cout << "PM      *" << "";
        }
        else if ( hours <= 12) //IF not, to use AM instead.
        {
            cout << "AM      *" << "";
        }

        cout << setw(5) << setfill(' ') << ""; //Setting gap between 12-hour and 24-hour clock displays.
        cout << "*       " << "";

        if (hours < 10) //IF hours variable is a single digit, display with an extra zero.
        {
            cout << "0" << hours << ":";
        }
        else if (hours == 24) //If the hours is at 24, which is invalid, display double zeroes.
        {
            cout << "00";
        }
        else //Otherwise, display hours as normal.
        {
            cout << hours << ":";
        }

        if (minutes < 10) //If minutes varialbe is a single digit, display with an extra zero.
        {
            cout << "0" << minutes << ":";
        }
        else //Otherwise, display as normal.
        {
            cout << minutes << ":";
        }

        if (seconds < 10) //If seconds variable is a single digit, display with an extra zero.
        {
            cout << "0" << seconds << " ";
        }
        else //Otherwise, display as normal.
        {
            cout << seconds << " ";
        }
        cout << "       *" << ""; //End specific line of clock display.
        cout << endl;

        cout << setw(25) << setfill('*') << ""; 
        cout << setw(5) << setfill(' ') << "";
        cout << setw(25) << setfill('*') << "";
        cout << endl; //Set final line of clock displays.
    }

    if (userMenuEntry == 2) //IF the user input was to change the minutes of the time.
    {
        cout << setw(25) << setfill('*') << "";
        cout << setw(5) << setfill(' ') << "";
        cout << setw(25) << setfill('*') << "";
        cout << endl; //Set top line of clock displays.

        cout << "*     12-Hour Clock     *" << "";
        cout << setw(5) << setfill(' ') << "";
        cout << "*     24-Hour Clock     *" << "";
        cout << endl; //Set second line of clock displays.

        cout << "*      " << ""; //Start third line of clock displays.
        if ( (hours > 0) && (hours < 10) ) //If hours is a single digit, display with an extra zero.
        {
            cout << "0" << hours << ":";
        }
        else if ((hours >= 10) && (hours <= 12))  //If double digit hour, display as normal.
        {
            cout << hours << ":";
        }
        else if (hours == 0) //Using 24-hour format to determine if midnight, to display "12" instead of "00".
        {
            cout << "12:";
        }
        else if ((hours - 12) >= 10 && (hours - 12) <= 12) //If the time is late evening to display without an extra zero and by itself.
        {
            cout << (hours - 12) << ":";
        }
        else //Otherwise, display hours as normal.
        {
            cout << "0" << (hours - 12) << ":";
        }

        if (minutes < 10) //If minutes is single digit, display with extra zero.
        {
            cout << "0" << minutes << ":";
        }
        else //If double digit, display as normal.
        {
            cout << minutes << ":";
        }

        if (seconds < 10) //If seconds is single digit, display with extra zero.
        {
            cout << "0" << seconds << " ";
        }
        else //If double digits, display as normal.
        {
            cout << seconds << " ";
        }

        if ((hours - 12) >= 0) //To determine whether PM or AM is needed.
        {
            cout << "PM      *" << "";
        }
        else if (hours <= 12) 
        {
            cout << "AM      *" << "";
        }

        cout << setw(5) << setfill(' ') << ""; //Set gap between clock displays.
        cout << "*       " << "";

        if (hours < 10) //If single digit, display an additional zero.
        {
            cout << "0" << hours << ":";
        }
        else if (hours == 24) //If hours at 24, which is invalid, enter double zeroes. 
        {
            cout << "00";
        }
        else  //Otherwise, display hours as normal.
        {
            cout << hours << ":";
        }

        if (minutes < 10) //If minutes is single digit, display additional zero.
        {
            cout << "0" << minutes << ":";
        }
        else //Otherwise, display minutes as normal.
        {
            cout << minutes << ":";
        }

        if (seconds < 10) //If seconds is single digit, display an additional zero.
        {
            cout << "0" << seconds << " ";
        }
        else //Display seconds as normal.
        {
            cout << seconds << " ";
        }
        cout << "       *" << "";
        cout << endl; //End third row of clock display.

        cout << setw(25) << setfill('*') << "";
        cout << setw(5) << setfill(' ') << "";
        cout << setw(25) << setfill('*') << "";
        cout << endl;//Set final line of clock display.
    }

    if (userMenuEntry == 3) //IF the user input was to change the seconds.
    {
        cout << setw(25) << setfill('*') << "";
        cout << setw(5) << setfill(' ') << "";
        cout << setw(25) << setfill('*') << "";
        cout << endl; //Set top row of clock display.

        cout << "*     12-Hour Clock     *" << "";
        cout << setw(5) << setfill(' ') << "";
        cout << "*     24-Hour Clock     *" << "";
        cout << endl; //Set second row of clock display.

        cout << "*      " << ""; //Start third row of clock display.
        if ((hours > 0) && (hours < 10)) //If hours is single digit, display with additional zero.
        {
            cout << "0" << hours << ":";
        }
        else if ((hours >= 10) && (hours <= 12))  //If double digit but between 10-12, display.
        {
            cout << hours << ":";
        }
        else if (hours == 0) //If hours is at zero, display "12" instead.
        {
            cout << "12:";
        }
        else if ((hours - 12) >= 10 && (hours - 12) <= 12) //If the time is late evening to display without an extra zero and by itself.
        {
            cout << (hours - 12) << ":";
        }
        else //Otherwise, display as normal.
        {
            cout << "0" << (hours - 12) << ":";
        }

        if (minutes < 10) //If single digit minute, display with additional zero.
        {
            cout << "0" << minutes << ":";
        }
        else //Otherwise, display as normal.
        {
            cout << minutes << ":";
        }

        if (seconds < 10) //If single digit second, display with additional zero.
        {
            cout << "0" << seconds << " ";
        }
        else //Otherwise, display as normal.
        {
            cout << seconds << " ";
        }

        if ((hours - 12) >= 0) //To determine if PM or AM is needed.
        {
            cout << "PM      *" << "";
        }
        else if (hours <= 12) 
        {
            cout << "AM      *" << "";
        }

        cout << setw(5) << setfill(' ') << "";
        cout << "*       " << ""; //Set gap between clock displays.

        if ((hours > 0) && (hours < 10)) //If single digit, display with additional zero.
        {
            cout << "0" << hours << ":";
        }
        else if ((hours == 24) || (hours == 0)) //If equal to 24, display "00" instead.
        {
            cout << "00:";
        }
        else //Otherwise, display as normal.
        {
            cout << hours << ":";
        }

        if (minutes < 10) //If single digit, display with additional zero.
        {
            cout << "0" << minutes << ":";
        }
        else //Otherwise, display as normal.
        {
            cout << minutes << ":";
        }

        if (seconds < 10) //If single digit, display with additional zero.
        {
            cout << "0" << seconds << " ";
        }
        else //Otherwise, display as normal.
        {
            cout << seconds << " ";
        }
        cout << "       *" << "";
        cout << endl; //End third row of clock displays.

        cout << setw(25) << setfill('*') << "";
        cout << setw(5) << setfill(' ') << "";
        cout << setw(25) << setfill('*') << "";
        cout << endl; //Set final row of clock display.
    }
}

void menuDisplay(int& userTime) //Function to display menu and ask for user input.
{ 
    int userMenuEntry; //Declare initial variables.
    bool userExit = false;

    while (userExit == false) { //Loop to continue to cycle until the user desires to exit.

        cout << endl;
        cout << "Please enter the desired number on the menu display: " << endl;
        cout << endl;

        //Display menu inside a box.
        cout << setfill('*') << setw(30) << "" << endl;
        cout << "* 1 - Add One Hour           *" << endl;
        cout << "* 2 - Add One Minute         *" << endl;
        cout << "* 3 - Add One Second         *" << endl;
        cout << "* 4 - Exit Program           *" << endl; 
        cout << setfill('*') << setw(30) << "" << endl;

        while (!(cin >> userMenuEntry) ) //Loop to verify the user input is an integer.
        { 
            cout << "Please enter a valid entry: " << endl;
            cin.clear();
            cin.ignore(100,'\n'); //If not, reset the input to try again.
        }
        
        if ((userMenuEntry < 1) || (userMenuEntry > 4)) //IF statement to make sure the integer is within the menu shown.
        {
            cout << "Invalid entry. Please try again." << endl;
        }

        if (userMenuEntry == 1) //IF statement if the user wants to increase the hours.
        {
            userTime = userTime + 10000; //Increase the time by one hour.
            if ((userTime / 10000) >= 24) //IF statement to check if the hours is at 24. 
            {
                userTime = userTime - 240000;//IF it is, reset the hours down to zero.
            }
            clockDisplay(userTime, userMenuEntry); //Enter function to display the clocks.
        }

        if (userMenuEntry == 2) //IF statement if the user wants to increase the minutes.
        {
            userTime = userTime + 100; //Increase the time by one minute.
            if ( ((userTime / 100) % 100) >= 60) //IF statement to check if the minutes is 60.
            {
                userTime = userTime + 4000; //IF it is, update the minutes by one by increasing userTime to 10000,
                                            //both resetting minutes to zero and hours to the next increment.
                if ((userTime / 10000) >= 24) //IF statement to check if the hours is at 24. 
                {
                    userTime = userTime - 240000;//IF it is, reset the hours down to zero.
                }
            }
            clockDisplay(userTime, userMenuEntry); //Enter function to display the clocks.
        }

        if (userMenuEntry == 3) //IF statement for if the user wants to increase the seconds.
        {
            userTime = userTime + 1; //Increase the time by one second.
            if ((userTime % 100) >= 60) //IF statement to check if the seconds is 60.
            {
                userTime = userTime + 40; //IF it is, update the minutes by one by increaseing userTime to "100",
                                          //both resetting seconds to zero and minutes to the next increment..
                if (((userTime / 100) % 100) >= 60) //IF statement to check if the minutes is 60.
                {
                    userTime = userTime + 4000; //IF it is, update the minutes by one by increasing userTime to 10000,
                                                //both resetting minutes to zero and hours to the next increment.
                    if ((userTime / 10000) >= 24) //IF statement to check if the hours is at 24. 
                    {
                        userTime = userTime - 240000; //IF it is, reset the hours down to zero.
                    }
                }
            }
            clockDisplay(userTime, userMenuEntry); //Enter function to display the clocks.
        }

        if (userMenuEntry == 4) //IF statement for if the user wishes to exit the program.
        {
            cout << "Exiting program. Thank you." << endl;
            userExit = true; //Marking "true" to exit the loop, ending the program.
        }
        
    }
}

void timeFormatCheck() //Function to both get the initial time and check to make sure the format is correct.
{ 
    bool timeChecker = false; //Variable to determine to exit the loop making sure the format is correct.
    int userTime; //Variable to receive user input.

    cout << "Please enter the initial time in either 12-hour or 24-hour format (Format: HHMMSS): " << endl;

    while (timeChecker == false)   //Initial loop while the format is incorrect.
    {  
        while (!(cin >> userTime)) //Loop to make sure the format is a proper integer.
        {
            cout << "Please enter a valid time in a proper format (HHMMSS): " << endl;
            cin.clear();  
            cin.ignore(100, '\n');  //Resetting the input for the next possible user input.
        }

        while ( ((userTime >= 240000) || (userTime < 0)) || ((userTime % 100) >= 60) || ((userTime % 10000) >= 6000) ) 
        {   
            cout << "Please enter a valid time in a proper format (HHMMSS): " << endl;
            cin >> userTime;  //Continue getting input to make sure the it is within proper time format.
        }

        if ( (!cin.fail()) && (userTime < 240000) && (userTime >= 0) && ((userTime % 100) < 60) && ((userTime % 10000) < 6000) ) 
        {
            timeChecker = true; //If the format is correct and a proper integer, set variable as true to exit the loop and continue.
        }
    }

    menuDisplay(userTime); //Enter the function to display the menu.
}

int main() //Beginning of program.
{
    timeFormatCheck(); //Enter function to get the initial time.

    return 0; //End of program.
}