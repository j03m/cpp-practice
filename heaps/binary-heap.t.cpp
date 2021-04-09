// test driver for binary-heap.cpp
#include "../lest.hpp";
#include "./binary-heap.cpp"
const lest::test specification[] =
{
    CASE( "Init" )
    {
        EXPECT( 0 == string(  ).length() );
        EXPECT( 0 == string("").length() );
    }
};

int main( int argc, char * argv[] )
{
    return lest::run( specification, argc, argv );
}