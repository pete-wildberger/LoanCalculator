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
    int miy;
    float Loan, Rate, Years, Balance, Term, Payment, totalInterest;
    miy = 12;
    totalInterest = 0;
//    input info
    std::cout << "\t\t Loan Calculator \n\n";
    std::cout << "Please enter the loan amount: \n";
    std::cin >> Loan;
    std::cout << "Please enter the loan rate: \n";
    std::cin >> Rate;
    std::cout << "Please enter the length in years of the loan: \n";
    std::cin >> Years;
//    calculation
    Term = pow((1 + Rate / miy), miy * Years);
    Payment = (Loan * Rate / miy * Term) / (Term-1);
//    display
//      formatting
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed | std::ios::showpoint | std::ios::left);
    std::cout << "Monthly payment: $" << Payment << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(10) << "Month";
    std::cout << std::setw(10) << "Interest";
    std::cout << std::setw(10) << "Principal";
    std::cout << std::setw(10) << "Balance" << std::endl;
    std::cout << "---------------------------------------\n";
    Balance = Loan;
//    loop to display monthly payments
    for (int Month = 0; Month < (miy * Years); Month++){
        float monthly, Principal;
//        monthly interest
        monthly = Rate / miy * Balance;
        Principal = Payment - monthly;
        std::cout << std::setw(10) << (Month + 1);
        std::cout << std::setw(10) << monthly;
        std::cout << std::setw(10) << Principal;
        std::cout << std::setw(10) << Balance << std::endl;
        Balance -= Principal;
        totalInterest += monthly;
    }
    std::cout << "---------------------------------------\n";
    std::cout << "Total Paid: "<< totalInterest + Loan << std::endl;
//    end program
    return 0;
}
