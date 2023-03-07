#include "checkingAccount.h"
#include <iomanip>
#include <iostream>

/*

    ;
    ;

    ;
    ;
    ;

    ;
    
    
    
*/

void checkingAccount::writeCheck(double amount)
{
    withdraw(amount);
}

void checkingAccount::print() const
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Interest on your checking account#:/t" << getAccountNumber()
    <<"/tBalance: $" << getBalance();
}

void checkingAccount::withdraw(double amount)
{
    if((balance - amount) > minimumBalance)
    {
        balance -= amount;
    }
    else if((balance - amount) < minimumBalance && (balance - amount - serviceCharge) > 0)
    {
        balance -= serviceCharge;
        std::cout << "Not enough funds to stay above minimum balance, service charge of " << serviceCharge << "exacted." << std::endl;
    }
    else
    {
        std::cout << "Not enough funds to withdraw. Transactioned failed" << std::endl;
    }
}

bool checkingAccount::verifyMinimumBalance(double amount)
{
    if(amount >= minimumBalance)
        return true;
    else
        return false;
}

double checkingAccount::getInterestRate() const
{
    return interestRate;
}

double checkingAccount::getServiceCharge() const
{
    return serviceCharge;
}

double checkingAccount::getMinimumBalance() const
{
    return minimumBalance;
}

void checkingAccount::setServiceCharges(double charges)
{
    serviceCharge = charges;
}

void checkingAccount::setInterestRate(double intRate)
{
    interestRate = intRate;
}

void checkingAccount::setMinimumBalance(double minBalance)
{
    minimumBalance = minBalance;
}

void checkingAccount::postInterest()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Interest gained on account : $" << (balance * (1.00 + interestRate)) << std::endl;
}

checkingAccount::checkingAccount(int acctNumber, double bal, double minBal = DEFAULT_MINIMUM_BALANCE, 
                    double intRate = DEFAULT_INTEREST_RATE_CHECKING, double ServC = DEFAULT_SERVICE_CHARGE);