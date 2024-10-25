/*
 * Investment.cpp
 *
 *  Date: October 02, 2024
 *  Name: Engred Vanegas
 */

#include "Investment.h"  // This includes the header file that contains the class definition
#include <iomanip>       // This used for formatting (setw, setfill)
#include <iostream>      // Included this in order to be able to perform input/output operations
#include <string> // Will use for manipulating strings
#include <sstream>       // Will use for string formatting with ostringstream

 // This is a function that will generate a string of repeated characters
std::string nCharString(size_t n, char c) {
    return std::string(n, c);
}

 // This constructor initializes the investment object with the user-provided values
Investment::Investment(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears)
    : m_initialInvestment(initialInvestment), m_monthlyDeposit(monthlyDeposit), m_annualInterest(annualInterest), m_numYears(numYears) {}

// These setter functions (mutators) modify the values of the private members
void Investment::setInitialInvestment(double t_initialInvestment) {
    m_initialInvestment = t_initialInvestment; // This sets the initial investment
}
void Investment::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit; // This sets the monthly deposit amount
}
void Investment::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest; // This sets the annual interest rate
}
void Investment::setNumYears(int t_numYears) {
    m_numYears = t_numYears; // This sets the investment's number of years
}

// These getter functions (accessors) retrieve the values of the private members
double Investment::getInitialInvestment() const { 
    return m_initialInvestment; // This returns the initial investment amount
}
double Investment::getMonthlyDeposit() const { 
    return m_monthlyDeposit; // This returns the monthly deposit amount
}
double Investment::getAnnualInterest() const { 
    return m_annualInterest; // This returns the annual interest rate
}
int Investment::getNumYears() const { 
    return m_numYears; // This returns the investment's number of years 
}

// This function formats the double value with a precision of 2 and concatenates the "$" sign
std::string formatCurrency(double value) {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2) << value;
    return "$" + output.str();
}

// This function displays the year-end balance without monthly deposit
void Investment::displayYearEndBalanceWithoutMonthlyDeposit() {
    double balance = m_initialInvestment;  // This variable stores the starting balance which is the initial investment
    double interestEarned;  // This variable stores the earned interest

    // This loops through each year in order to calculate both the balance and interest
    for (int year = 1; year <= m_numYears; ++year) {
        interestEarned = balance * (m_annualInterest / 100.0);  // This calculates the interest earned for the year
        balance += interestEarned;  // This updates the balance including the interest earned

        // This outputs the year, balance, and interest with proper formatting
        std::cout << "|  " << std::setw(2) << year
            << "                        " << std::setw(10) << formatCurrency(balance)
            << "                             " << std::setw(10) << formatCurrency(interestEarned) 
            << "           |" << std::endl;
    }
}

// This function displays the year-end balance with monthly deposits
void Investment::displayYearEndBalanceWithMonthlyDeposit() {
    double balance = m_initialInvestment;  // This variable stores the starting balance which is the initial investment
    double interestEarned;  // This variable stores the earned interest
    double totalInterest = 0;  // This variable stores the total interest earned each year

    // This loops through each year in order to calculate the balance and interest including monthly deposits
    for (int year = 1; year <= m_numYears; ++year) {
        totalInterest = 0;  // Reset total interest for the year

        // This loops through each month
        for (int month = 1; month <= 12; ++month) {
            // This calculates the monthly interest
            interestEarned = (balance + m_monthlyDeposit) * ((m_annualInterest / 100.0) / 12);
            balance += m_monthlyDeposit + interestEarned;  // This updates the balance including both the monthly deposit and interest
            totalInterest += interestEarned;  // This adds the monthly interest to the total for the year
        }

        // This outputs the year, balance, and interest with proper formatting
        std::cout << "|  " << std::setw(2) << year
            << "                          " << std::setw(10) << formatCurrency(balance)
            << "                             " << std::setw(10) << formatCurrency(totalInterest)
            << "         |" << std::endl;
    }
}

// This function displays the monthly breakdown of compound interest with monthly deposits
void Investment::displayMonthlyBreakdown() {
    double openingAmount = m_initialInvestment; // This variable is the opening balance at the start of the investment
    double interestEarned; // This variable stores the interest that is earned each month
    double closingBalance; // This variable stores the balance at the end of each month

    // This loops through each year and month in order to display the breakdown
    for (int month = 1; month <= m_numYears * 12; ++month) {
        // This calculates the interest for the current month
        interestEarned = (openingAmount + m_monthlyDeposit) * ((m_annualInterest / 100.0) / 12);
        closingBalance = openingAmount + m_monthlyDeposit + interestEarned;

        // This outputs the formatted values for each month
        std::cout << "| " << std::setw(3) << month << "   | "
            << std::setw(10) << formatCurrency(openingAmount) << "      | "
            << std::setw(10) << formatCurrency(m_monthlyDeposit) << "       | "
            << std::setw(10) << formatCurrency(openingAmount + m_monthlyDeposit) << "   | "
            << std::setw(7) << formatCurrency(interestEarned) << "   | "
            << std::setw(11) << formatCurrency(closingBalance) << "       |" << std::endl;

        // This updates the opening amount for the next month
        openingAmount = closingBalance;

        // This adds a separation line for every 12 months, it prints a separator to indicate the end of the year for better readibility
        if (month % 12 == 0) {
            std::cout << "+" << nCharString(91, '=') << "+" << std::endl;
        }
        // This adds a separation line for every month, it prints a separator to indicate the end of the month for better readibility
        else {
            std::cout << "+" << nCharString(91, '.') << "+" << std::endl;
        }
    }
}
