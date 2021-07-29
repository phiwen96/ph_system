#include <catch2/catch.hpp>
#include <ph_system/system.hpp>

using namespace std;

template <bool endline = true, int mellanrum = 10>
void out (auto&&... s) noexcept
{
    ((cout << left << setw (mellanrum) << s), ...);
    cout << setw (0);
    
    if constexpr (endline)
        cout << endl;
}


TEST_CASE ("")
{
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    auto i = 11;
    
    
    cout << "i = " << i << endl;
    
    cout << "hello world" << " bajs" <<  " skmkm" << endl << endl << "jdf";
    
    while (i < 12) // kör det mellan måsvingarna en gång om i är mindre än 12
    {
        cout << "Nils oskuld ej hittad!" << endl;
        i = 13;
    }
    
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    constexpr auto res = ph::system::Darwin or ph::system::Linux or ph::system::Windows;
    constexpr auto res2 = ph::system::Arm64 or ph::system::X86_64;
    
    REQUIRE (res);
    REQUIRE (res2);
    
    
    
    cout << "Darwin" << left << setw (10) << ph::system::Darwin << endl;
    cout << "Linux" << left << setw (10) << ph::system::Linux << endl;
    cout << "Windows" << left << setw (10) << ph::system::Windows << endl << endl;
    
    cout << "Arm64" << right << setw (10) << ph::system::Arm64 << endl;
    cout << "X86_64" << left << ph::system::X86_64 << endl;
    
    out (0, "a", "b", "aa", "ccc");
    
}
