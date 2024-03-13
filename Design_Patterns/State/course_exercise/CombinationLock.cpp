#include "CombinationLock.h"

void CombinationLock::reset()
{
    status = "LOCKED";
    digits_entered = 0;
    failed = false;
}

CombinationLock::CombinationLock(const vector<int> &combination) : combination(combination) 
{
    reset();
}

void CombinationLock::enter_digit(int digit)
{
    if (status == "LOCKED") status = "";
        status +=  to_string(digit);
    if (combination[digits_entered] != digit)
    {
        failed = true; 
    }
    digits_entered++;

    if (digits_entered == combination.size())
    {
        status = failed ? "ERROR" : "OPEN";
        if(status.compare("ERROR") == 0)
        {
            std::cout << "Combinatia introdusa nu este valida, incercati din nou!";
            reset();
        }
    }
}
