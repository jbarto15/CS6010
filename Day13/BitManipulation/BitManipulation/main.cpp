//
//  main.cpp
//  BitManipulation
//
//  Created by Josh Barton on 9/8/23.
//

#include <iostream>
#include "bits.h"

int main(int argc, const char * argv[]) {
    //tests should go in here
    
    std::cout << "Num Of Bits Set: " << NumBitsSet(10) << std::endl;
    
    TestBool( GetBit( 0, 0 ), false, "GetBit1" );
    TestBool( GetBit( 0, 1 ), false, "GetBit2" );
    TestBool( GetBit( 0, 31 ), false, "GetBit3" );
    TestBool( GetBit( -1, 0 ), true, "GetBit4" );
    TestBool( GetBit( -1, 1 ), true, "GetBit5" );
    TestBool( GetBit( -1, 31 ), true, "GetBit6" );
    TestBool( GetBit( 0xAAAAAAAA, 0 ), false, "GetBit7" );
    TestBool( GetBit( 0xAAAAAAAA, 16 ), false, "GetBit8" );
    TestBool( GetBit( 0xAAAAAAAA, 17 ), true, "GetBit9" );
    TestBool( GetBit( 0xAAAAAAAA, 31 ), true, "GetBit10" );
    
    
    TestBool( IsNegative( 0 ), false, "IsNegative1" );
    TestBool( IsNegative( 1 ), false, "IsNegative2" );
    TestBool( IsNegative( -1 ), true, "IsNegative3" );
    TestBool( IsNegative( 0xAAAAAAAA ), true, "IsNegative4" );
    TestBool( IsNegative( 0x55555555 ), false, "IsNegative5" );
    TestBool( IsNegative( INT_MIN ), true, "IsNegative6" );
    TestBool( IsNegative( INT_MAX ), false, "IsNegative7" );
    
    
    Test32Bit( NumBitsSet( 0 ), 0, "NumBitsSet1" );
    Test32Bit( NumBitsSet( 1 ), 1, "NumBitsSet2" );
    Test32Bit( NumBitsSet( 2 ), 1, "NumBitsSet3" );
    Test32Bit( NumBitsSet( 3 ), 2, "NumBitsSet4" );
    Test32Bit( NumBitsSet( 5 ), 2, "NumBitsSet5" );
    Test32Bit( NumBitsSet( -1 ), 32, "NumBitsSet6" );
    Test32Bit( NumBitsSet( 0xAAAAAAAA ), 16, "NumBitsSet7" );
    Test32Bit( NumBitsSet( 0x55555555 ), 16, "NumBitsSet8" );
    
    
    Test8Bit( GetByte( 0, 0 ), 0, "GetByte1" );
    Test8Bit( GetByte( 0, 1 ), 0, "GetByte2" );
    Test8Bit( GetByte( 0, 2 ), 0, "GetByte3" );
    Test8Bit( GetByte( 0, 3 ), 0, "GetByte4" );
    Test8Bit( GetByte( 0xAAAAAAAA, 0 ), 0xaa, "GetByte4" );
    Test8Bit( GetByte( 0xAAAAAAAA, 1 ), 0xaa, "GetByte5" );
    Test8Bit( GetByte( 0xAAAAAAAA, 2 ), 0xaa, "GetByte6" );
    Test8Bit( GetByte( 0xAAAAAAAA, 3 ), 0xaa, "GetByte7" );
    Test8Bit( GetByte( 0x12345678, 0 ), 0x78, "GetByte8" );
    Test8Bit( GetByte( 0x12345678, 1 ), 0x56, "GetByte9" );
    Test8Bit( GetByte( 0x12345678, 2 ), 0x34, "GetByte10" );
    Test8Bit( GetByte( 0x12345678, 3 ), 0x12, "GetByte11" );
    
    
    
    return 0;
}
