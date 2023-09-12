//
//  bits.h
//  BitManipulation
//
//  Created by Josh Barton on 9/8/23.
//

#ifndef bits_h
#define bits_h

using std::cout;
using std::endl;
using std::string;

bool GetBit( uint32_t input, int b );


bool IsNegative( int input );


int NumBitsSet( uint32_t input );


unsigned char GetByte( uint32_t input, int b );


uint32_t SetByte( uint32_t input, uint8_t value, int b );


int Negate( int input );


int Increment( uint32_t x );




void Test32Bit( int a, int b, const string & message );


void Test8Bit( unsigned char a, unsigned char b, const string & message );


void TestBool( bool a, bool b, const string & message );





#endif /* bits_h */
