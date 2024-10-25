/*
 * main.cpp
 *
 *  Date: October 02, 2024
 *  Name: Engred Vanegas
 */

#include <iostream> // Included this in order to be able to perform input/output operations
#include "Investment.h" // This includes the header file that contains the class definition
#include <string> // Will use for manipulating strings
#include <iomanip> // Will use for formatting numerical outputs like setprecision

// This is a function that will validate positive input
double getPositiveInput(const std::string& prompt) {
    double value;
    do {
        std::cout << prompt; // This will be the prompt that will be asked to the user
        std::cin >> value; // This will read the input value that the user has entered when prompted to

        // This checks if the input value that the user entered upon prompt is positive or negative
        // If it's positive it proceeds to prompt user's for their answers, make the calculations and display the charts
        // But if it's negative then it will not proceed until a positive value is entered
        if (value <= 0) {
            std::cout << "Invalid input. Please enter a positive value." << std::endl;
        }
    } while (value <= 0);
    return value;
}

int main() {
    char continueInput; // This variable stores the user's choice to either continue or exit
    // The loop begins, it asks the user for inputs, performs calculations (found in Investment.cpp, and displays charts
    do {
        // This prompts the user to input values (details) for the account while using the validation function
        double initialInvestment = getPositiveInput("Enter Initial Investment Amount: $"); // This prompts the user to input the initial investment value

        double monthlyDeposit = getPositiveInput("Enter Monthly Deposit: $"); // This prompts the user to input the initial investment value

        double annualInterest = getPositiveInput("Enter Annual Interest Rate: %"); // This prompts the user to input the initial investment value

        int numYears = static_cast<int>(getPositiveInput("Enter Number of Years: ")); // This prompts the user to input the initial investment value

        // This displays the header for the data input
        std::cout << std::endl << nCharString(35, '*') << std::endl;
        std::cout << std::endl << nCharString(10, '*') << " Data Input " << nCharString(13, '*') << std::endl;

        // This displays the entered data with proper formatting
        std::cout << "Initial Investment Amount:   $" << std::fixed << std::setprecision(2) << initialInvestment << std::endl;
        std::cout << "Monthly Deposit:             $" << std::fixed << std::setprecision(2) << monthlyDeposit << std::endl;
        std::cout << "Annual Interest:             " << std::fixed << std::setprecision(0) << annualInterest << "%" << std::endl;
        std::cout << "Number of Years:             " << numYears << std::endl;

        std::cout << std::endl << "Press ENTER to continue..." << std::endl;
        std::cin.ignore(); // This pauses the screen
        std::cin.get(); // This waits for the user's input in order to continue

        // This creates an investment object using the user's input
        Investment investment(initialInvestment, monthlyDeposit, annualInterest, numYears);

        // This displays the results without monthly deposits
        std::cout << std::endl << "+" << nCharString(88, '-') << "+" << std::endl; // This adds the upper border of dashes to the chart being displayed
        std::cout << "|" << nCharString(25, ' ') << "Balance and Interest Without Monthly Deposits" << nCharString(18, ' ') << "|"; // This is the chart's title header 
        std::cout << std::endl << "+" << nCharString(88, '.') << "+" << std::endl; // This adds the border of equal signs beneath of the chart's title header for a clean separation between title and subtitle
        std::cout << "|  Year" << nCharString(19, ' ') << "Year-End Balance" << nCharString(19, ' ') << "Year-End Earned Interest" << nCharString(4, ' ') << "|"; // This is the chart's subtitle header
        std::cout << std::endl << "+" << nCharString(88, '.') << "+" << std::endl; // This adds the border of dashes beneath the subtitle header of the chart being displayed for a clean separation between the subtitle and data
        investment.displayYearEndBalanceWithoutMonthlyDeposit(); // This calls the function in order to display the results without monthly deposits
        std::cout << "+" << nCharString(88, '-') << "+" << std::endl; // This adds the lower border of dashes to the chart being displayed

        // This displays the results with monthly deposits
        std::cout << std::endl << "+" << nCharString(88, '-') << "+" << std::endl; // This adds the upper border of dashes to the chart being displayed
        std::cout << "|" << nCharString(25, ' ') << "Balance and Interest With Monthly Deposits" << nCharString(21, ' ') << "|"; // This is the chart's title header 
        std::cout << std::endl << "+" << nCharString(88, '.') << "+" << std::endl; // This adds the border of equal signs beneath of the chart's title header for a clean separation between title and subtitle
        std::cout << "|  Year" << nCharString(19, ' ') << "Year-End Balance" << nCharString(19, ' ') << "Year-End Earned Interest" << nCharString(4, ' ') << "|"; // This is the chart's subtitle header
        std::cout << std::endl << "+" << nCharString(88, '.') << "+" << std::endl; // This adds the border of dashes beneath the subtitle header of the chart being displayed for a clean separation between the subtitle and data
        investment.displayYearEndBalanceWithMonthlyDeposit(); // This calls the function in order to display the results with monthly deposits
        std::cout << "+" << nCharString(88, '-') << "+" << std::endl; // This adds the lower border of dashes to the chart being displayed

        // This displays the legend for the third chart before showing the monthly breakdown
        std::cout << std::endl;
        std::cout << std::endl << nCharString(15, ' ') << nCharString(25, '*') << " Legend " << nCharString(30, '*') << std::endl;
        std::cout << nCharString(15, ' ') << "*  Each row represents one month of investment breakdown." << nCharString(5, ' ') << "*" << std::endl;
        std::cout << nCharString(15, ' ') << "*" << nCharString(61, ' ') << "*" << std::endl;
        std::cout << nCharString(15, ' ') << "*  The '...........' separates the months." << nCharString(20, ' ') << "*" << std::endl;
        std::cout << nCharString(15, ' ') << "*" << nCharString(61, ' ') << "*" << std::endl;
        std::cout << nCharString(15, ' ') << "*  The '==========' indicates the end of a year (12 months)." << nCharString(2, ' ') << "*" << std::endl;
        std::cout << nCharString(15, ' ') << nCharString(63, '*') << std::endl;

        // This displays the headers for the monthly breakdown chart
        std::cout << std::endl << "+" << nCharString(91, '-') << "+" << std::endl;
        std::cout << "| Month | Opening Amount  | Deposited Amount |    Total     |  Interest |  Closing Balance  |" << std::endl;
        std::cout << "+" << nCharString(91, '-') << "+" << std::endl;

        // This displays the monthly breakdown chart
        investment.displayMonthlyBreakdown();

        std::cout << "+" << nCharString(91, '-') << "+" << std::endl;  // This closes the table at the end

        // This asks the user if they want to test other values or exit
        std::cout << std::endl << "Would you like to test other values? (Y/N): ";
        std::cin >> continueInput;

        // This checks for any newline characters that may be present in order to avoid issues with input for next loop iterations
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (continueInput == 'Y' || continueInput == 'y');  // Depending on the user's choice, they can either continue inputting values or exit

    // When the user chooses to exit, a friendly message is displayed, indicating the end of the program
    std::cout << "Exiting program, goodbye!" << std::endl;
    
    return 0; // This indicates a successful execution, end of program
}
