
// Aeriel Sacia
//project 2 

#include <vector>
#include <iostream>
#include "Calculations"
#include "InvestmentInfo"

using namespace std;

//user inputs for investment info 
double openAmt =  t_userData.getInitialInvestAmt();
double depAmt =  t_userData.getMonthlyDep();
int intRate =  t_userData.getAnnualInt();
int numYears =  t_userData.getNumYears();
vector<int> years;
vector<vector<double>> yearEndBals;

//returns array for ints and displays
for (int i = 0; i < numYears; ++i) {
    years.push_back(i + 1);
}

if (t_monthlyDep == false) {
	//without monthly 
	
	 yearEndBals = annualBalWithInt(openAmt, 0, intRate, numYears);
} else {
	// with monthly
	yearEndBals = annualBalWithInt(openAmt, depAmt, intRate, numYears);
}

return investmentDetails;
}

//Calculations for annual balance with the interest
vector<vector<double>> balanceAndInts;
vector<double> annualInterestOnly;
vector<double> annualBalWithInterest;
double newBal;
double yearEndInt;
double precIntRate = (t_intRate/100.00)/12.00;
double intTracker = 0;
double intOnly = 0;
//loop for time frame

for (int i = 0; i < (t_years * 12); ++i) {
    yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i+1))) * precIntRate;
//earned interest and the intital balance
    if (((i+1) % 12) == 0) {
        annualInterestOnly.push_back(yearEndInt - intOnly); // Add annual interest
        intOnly = yearEndInt;
        newBal = t_openAmount + (t_depositAmount * (i+1)) + yearEndInt; //interest, opening, & monthly amount
        annualBalWithInterest.push_back(newBal); // annual bal with interest
    }
}
if (newBal > MAX_AMOUNT ) {
    throw runtime_error("Calculation error");
}
balanceAndInts.push_back(annualInterestOnly); // tracking interest
balanceAndInts.push_back(annualBalWithInterest); // tracking interest + balance



return balanceAndInts;
}







