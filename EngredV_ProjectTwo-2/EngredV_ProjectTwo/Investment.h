/*
 * Investment.h
 *
 *  Date: October 02, 2024
 *  Name: Engred Vanegas
 */

// This header guard prevents multiple inclusion
#ifndef PROJECT_TWO_INVESTMENT_H_ 
#define PROJECT_TWO_INVESTMENT_H_

#include <iostream> // Included this in order to be able to perform input/output operations

// This is the Class definition for the Investment Class
// It represents an investment account and it holds information about
// the initial investment, monthly deposit, annual interest rate, and the number of years
class Investment {
private:
    // These a private data members that are used to store investment details
    double m_initialInvestment;  // This variable holds the initial investment amount
    double m_monthlyDeposit;     // This variable holds the monthly deposit amount
    double m_annualInterest;     // This variable holds the annual interest rate (in percentage)
    int m_numYears;              // This variable holds the investment's number of years

public:
    // This constructor initializes an investment object with the user-provided values
    Investment(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears);

    // These are the setters (mutators) for the class members
    void setInitialInvestment(double t_initialInvestment);  // This setter sets the initial investment
    void setMonthlyDeposit(double t_monthlyDeposit);        // This setter sets the monthly deposit
    void setAnnualInterest(double t_annualInterest);        // This setter sets the annual interest rate
    void setNumYears(int t_numYears);                       // This setter sets the investment's number of years

    // These are the getters (accessors) for the class members
    double getInitialInvestment() const;  // This getter returns the initial investment amount
    double getMonthlyDeposit() const;     // This getter returns the monthly deposit amount
    double getAnnualInterest() const;     // This getter returns the annual interest rate
    int getNumYears() const;              // This getter returns the investment's number of years 

    // This function displays the year-end balance without considering monthly deposits
    void displayYearEndBalanceWithoutMonthlyDeposit();

    // This function displays the year-end balance considering monthly deposits
    void displayYearEndBalanceWithMonthlyDeposit();

    // This function displays the monthly breakdown of compound interest with deposits
    void displayMonthlyBreakdown();
};

// Utility function to generate a string of repeated characters
std::string nCharString(size_t n, char c);

#endif // This marks this end of the #ifndef block

