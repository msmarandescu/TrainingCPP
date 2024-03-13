#include "CombinationLock.h"

int main()
{
    const vector<int> comb= {1,2,3,4};
    CombinationLock lock(comb);

    std::cout << "enter 4 digit number, une digit at the time, to unlock:\n";
    while(lock.status.compare("OPEN"))
    {
      int digit; 
      std::cin >> digit;
      lock.enter_digit(digit);    
      std::cout << "lock status: " << lock.status << std::endl;
    }

    return 0;
}
