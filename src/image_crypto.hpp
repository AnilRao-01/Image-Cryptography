#ifndef LFSR
#define LFSR
#include <iostream>
#include <string>


using namespace std;

class FibLFSR
{
    public:
        FibLFSR(string seed);
        int step(void);
        int generate(int k);
	friend ostream& operator << (ostream &out, const FibLFSR& reg);    
    private:
        string bit_string;
};



#endif
