//
//  main.cpp
//  LoanCalculator
//
//  Created by Peter on 10/14/17.
//  Copyright © 2017 Peter. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <math.h>

int main(int argc, const char * argv[]) {
//    initialize variables
    float Loan, Rate, Years, Balance, Term, Payment;
    std::cout << "\t\t Loan Calculator \n\n";
    std::cout << "Please enter the loan amount: \n";
    std::cin >> Loan;
    std::cout << "Please enter the loan rate: \n";
    std::cin >> Rate;
    std::cout << "Please enter the length in years of the loan: \n";
    std::cin >> Years;
    Term = pow((1 + Rate / 12), 12 * Years);
    Payment = (Loan * Rate / 12 * Term) / (Term-1);
//    end program
    return 0;
}
