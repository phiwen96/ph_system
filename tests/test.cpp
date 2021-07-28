#include <catch2/catch.hpp>
#include <ph_system/system.hpp>

using namespace std;




TEST_CASE ("")
{
    constexpr auto res = ph::system::Darwin or ph::system::Linux or ph::system::Windows;
    constexpr auto res2 = ph::system::Arm64 or ph::system::X86_64;
    
    REQUIRE (res);
    REQUIRE (res2);
    
    
    
    cout << "Darwin" << setw (10) << ph::system::Darwin << endl;
    cout << "Linux" << setw (10) << ph::system::Linux << endl;
    cout << "Windows" << setw (10) << ph::system::Windows << endl << endl;
    
    cout << "Arm64" << setw (10) << ph::system::Arm64 << endl;
    cout << "X86_64" << setw (10) << ph::system::X86_64 << endl;
    
    
}
