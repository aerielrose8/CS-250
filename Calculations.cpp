
}
#include <vector>
#include <iostream>
#include "Calculations.h"
#include "InvestmentInfo.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

// Default constructor
Calculations::Calculations() {}

//user input builds InvestmentInfo object that contains user balance & interest info.

InvestmentInfo Calculations::calculateAnnualInvestment(DataInput& t_userData, bool t_monthlyDep) {
    // organize user input
    double openAmt =  t_userData.getMInitialInvestAmt();
    double depAmt =  t_userData.getMMonthlyDep();
    int intRate =  t_userData.getMAnnualInt();
    int numYears =  t_userData.getMNumYears();
    vector<int> years;
    vector<vector<double>> yearEndBals;

    // store data for our report
    InvestmentInfo investmentDetails;

    try {


        for (int i = 0; i < numYears; ++i) {
            years.push_back(i + 1);
        }

        if (t_monthlyDep == false) { //without monthly deposit
            yearEndBals = annualBalWithInt(openAmt, 0, intRate, numYears);
        } else { // with monthly deposits
            yearEndBals = annualBalWithInt(openAmt, depAmt, intRate, numYears);
        }

        investmentDetails.setMYears(years);
        investmentDetails.setMYearEndEarnedInterests(yearEndBals.at(0));
        investmentDetails.setMYearEndBalances(yearEndBals.at(1));

        return investmentDetails;
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }

}

vector<vector<double>> Calculations::annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {
    // Local variables for accurate calculations
    vector<vector<double>> balanceAndInts;
    vector<double> annualInterestOnly;
    vector<double> annualBalWithInterest;
    double newBal;
    double yearEndInt;
    double precIntRate = (t_intRate/100.00);
    double intTracker = 0;
    double intOnly = 0;

    // Loop months calculate annual balance and the earned interest
    for (int i = 0; i < (t_years * 12); ++i) {
        yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i+1))) * precIntRate;
        // tracking earned interest
        intTracker = yearEndInt;
        if (((i+1) % 12) == 0) {
            intOnly = yearEndInt;
            newBal = t_openAmount + (t_depositAmount * (i+1)) + yearEndInt;
            annualBalWithInterest.push_back(newBal);
        }
    }

    balanceAndInts.push_back(annualInterestOnly); //  tracking interest
    balanceAndInts.push_back(annualBalWithInterest); //  tracking interest and balance


    return balanceAndInts;
}

