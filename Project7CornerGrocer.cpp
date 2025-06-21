/*
 *  Project7CornerGrocer.cpp
 *
 *  Date: 2025-06-22
 *  Author: Scott Weiss
 */

#include <iostream> //Include all necessary libraries needed for the program.
#include <iomanip>
#include <fstream>
#include <string>
#include <map>

bool exitChoice = false; //Initialize exitChoice variable.

class ProduceInventory { //Initialize Class.
	public:
		void intializeMap() { //Initialize initial map.
			std::ifstream inFS;
			inFS.open("CS210_Project_Three_Input_File.txt"); //Open the initial input file.

			if (!inFS.is_open()) { //If unable to open, print error message.
				std::cout << "Unable to open CS210_Project_Three_Input_File.txt." << std::endl;
				return;
			}
			
			int produceCount = 1;
			std::string produce;
			
			while (inFS >> produce) { //While getting input from file.
				
				if (produceMap.count(produce) > 0) { //If it already exists in the map, add one to existing count.
					produceMap.at(produce) += 1;
				}
				else { //If not, create it's spot with an initial count of 1.
					produceMap.emplace(produce, produceCount);
				}
				
			}
			inFS.close(); //Close input file.
		}
		
		void separateFrequency() { //Function to print out separate frequency of desired item.
			
			std::string produceInput; //Initialize input variable.
			std::cout << "Enter produce to search for: ";
			std::cin >> produceInput; //Get desired input.
			std::cout << std::endl;
			
			//Check if desired input exists in the map. If so, print the necessary output.
			if (produceMap.count(produceInput)) { 
				std::cout << produceInput << " " << produceMap.at(produceInput) << std::endl;
			}
			else { //If it does not exist, print error messages.
				std::cout << "Input is either not valid or does not exist in the produce list. Please try again." << std::endl;
				std::cout << "Please remember that the input of produce is case sensitive. Example: 'Apples' instead of 'apples'." << std::endl;
			}
		}

		void allFrequencies() { //Function to list all frequencies.

			std::cout << "Frequency of all produce items: " << std::endl;

			std::map<std::string, int>::iterator iter; //Create iteration map to go through frequency map.

			for (iter = produceMap.begin(); iter != produceMap.end(); iter++) {
				//Starting from beginning to end, print out each key with the associated frequency value, then start a new line.
				std::cout << iter->first << " " << iter->second << std::endl;
			}
		}

		void frequencyHistogram() { //Function for histogram of frequencies.

			std::cout << "Histogram of frequency of all produce items: " << std::endl;

			std::map<std::string, int>::iterator iter; //Create iteration map to go through frequency map.

			for (iter = produceMap.begin(); iter != produceMap.end(); iter++) {
				
				//Starting from beginning to end, print out each key, then the associated value in desired format.
				std::cout << iter->first << " " << std::setfill('*') << std::setw(iter->second) << "" << std::endl;
			}
		}

		void exitBackup() { //Backup function upon exiting.

			std::ofstream outFS;
			outFS.open("frequency.dat"); //Create desired exit file.

			if (!outFS.is_open()) { //If it does not exist, print error message.
				std::cout << "Unable to open frequency.dat." << std::endl;
			}

			std::map<std::string, int>::iterator iter; //Create iteration map to go through map keys.

			for (iter = produceMap.begin(); iter != produceMap.end(); iter++) {
				//Starting from beginning going to the end, print out each key with its associated value, then go to a new line.
				outFS << iter->first << " " << iter->second << std::endl;
			}
			outFS.close(); //Close the output file.
		}

	private: //Create private map for containing produce names and frequencies.
		std::map<std::string, int> produceMap;
		
};

void menuOptions() { //Function for menu options.

	std::string userInput = " "; //Initialize for menu choice selection.
	
	ProduceInventory produce; //Initialize class variable to call functions.
	produce.intializeMap(); //Initialize the map for getting frequencies.

	while (userInput != "4") { //Enter loop of menu choices.

		std::cout << "Please enter desired menu option: ";
		std::cin >> userInput; //Get user input for menu selection.
		std::cout << std::endl;

		if (userInput == "1") { //Option 1, call function for getting separate frequencies.
			produce.separateFrequency();
			return;
		}

		if (userInput == "2") { //Option 2, call function to list all frequencies.
			produce.allFrequencies();
			return;
		}

		if (userInput == "3") { //Option 3, call function to list histogram of all frequencies.
			produce.frequencyHistogram();
			return;
		}

		if (userInput == "4") { //Option 4, call function to create backup of frequencies and then exit program.
			produce.exitBackup();
			std::cout << "Now exiting program. Thank you." << std::endl;
			exitChoice = true; //Make exitChoice variable "true" to exit loop in previous function.
		}

		//If none of the above options are entered, ask for valid input.
		if ((userInput != "1") && (userInput != "2") && (userInput != "3") && (userInput != "4")) {
			std::cout << "Please enter valid input." << std::endl;
			std::cout << std::endl;
		}
	}

}

void InitialMenu() { //Display initial menu.

	while (exitChoice == false) { //While the user does not wish to exit.

		//Formatting for the menu display and displaying the menu of choices.
		std::cout << std::endl;
		std::cout << std::setfill('*') << std::setw(63) << "" << std::endl; 
		std::cout << "* 1: Lone frequency of desired produce" << std::setfill(' ') << std::setw(24) << "" << "*" << std::endl;
		std::cout << "* 2: Entire produce list with purchase frequency" << std::setfill(' ') << std::setw(14) << "" << "*" << std::endl;
		std::cout << "* 3: Histogram of entire produce list with purchase frequency *" << std::endl;
		std::cout << "* 4: Exit program" << std::setfill(' ') << std::setw(45) << "" << "*" << std::endl;
		std::cout << std::setfill('*') << std::setw(63) << "" << std::endl;
		std::cout << std::endl;

		menuOptions(); //Call the function for menu choices.
	}
}

int main() //Start main program.
{
	InitialMenu(); //Call the initial menu display.

	return 0; //End program.
}
