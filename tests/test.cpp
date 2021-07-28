#include <catch2/catch.hpp>
#include <ph_system/system.hpp>

using namespace std;




TEST_CASE ("")
{
    constexpr auto res = ph::system::Darwin or ph::system::Arm64 or ph::system::Linux or ph::system::Windows or ph::system::X86_64;
    
    REQUIRE (res);
    
    cout << "Darwin" << setw (10) << ph::system::Darwin << endl;
    cout << "Arm64" << setw (10) << ph::system::Arm64 << endl;
    cout << "Linux" << setw (10) << ph::system::Linux << endl;
    cout << "Windows" << setw (10) << ph::system::Windows << endl;
    cout << "X86_64" << setw (10) << ph::system::X86_64 << endl;
}
