/*
 * datainput.h
 *
 *  Created on: Dec 8, 2020
 *      Author: 1731847_snhu
 */

#ifndef DATAINPUT_H_
#define DATAINPUT_H_

class DataInput {
public:
	 DataInput();

	    const vector<string> &getUserPrompts() const;

	    double getInitialInvestAmt() const;

	    void setInitialInvestAmt(double t_initialInvestAmt);

	    double getMonthlyDep() const;

	    void setMonthlyDep(double t_monthlyDep);

	    double getMAnnualInt() const;

	    void setAnnualInt(double t_annualInt);

	    double getNumYears() const;

	    void setNumYears(double t_numYears);

	    void promptUser();

private:
	    vector<string> userPrompts;

	    double initialInvestAmt;

	    double monthlyDep;

	    double annualInt;

	    double numYears;

	    void printHeader();

	    vector<double> input();

	    bool enterCheck();
	};

#endif /* DATAINPUT_H_ */
