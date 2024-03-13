#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
private:
    vector<int> combination;
    int digits_entered{0};
    bool failed{false};
    
public:
    string status;

    void reset();
    CombinationLock(const vector<int> &combination);
    void enter_digit(int digit);
};