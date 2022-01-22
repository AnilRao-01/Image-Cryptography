#ifndef crypto
#define crypto
#include <iostream>
#include <string>
#include "image_crypto.hpp"

FibLFSR::FibLFSR(string seed)
{
    bit_string = seed;
}
int FibLFSR::step(void) // simulate one step and return newly generated bit
{
	int pos_15 = static_cast<int>(bit_string.at(0)); 
	int pos_13 = static_cast<int>(bit_string.at(2));
	int pos_12 = static_cast<int>(bit_string.at(3));
	int pos_10 = static_cast<int>(bit_string.at(5));
	int new_bit = pos_15 ^ pos_13;
	new_bit = new_bit ^ pos_12;
	new_bit = new_bit ^ pos_10;
	bit_string.erase(0,1);
	bit_string.append(to_string(new_bit));
	
	return new_bit;
}
int FibLFSR::generate(int k) //preform step() method k times and return integer generated
{
	int num = 0;

	for(int i = 0; i < k; i++)
	{
		num = num * 2;
		num = num + step();		
	}

	return num;
}

ostream& operator << (ostream &out, const FibLFSR& reg)
{
	out << reg.bit_string;
	return out;
}


#endif

