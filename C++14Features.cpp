===============================================================
//   1. Generic Lambdas
// ============================================================  
   auto x = [](auto a, auto b)
   {
       return a + b;
   };

   cout << x(2,3) <<endl;
   std::string str1 = "Suraj ", str2 = "Hengne";
   cout << x(str1, str2) <<endl;
===============================================================
// 2.  Return Type Deduction (auto, decltype)
// ===============================================================
 auto increment(int a)
 {
   ++a;
   return a;   
 }

int p  = 10;
cout << increment(10) <<endl;
----------------------------------------------------------------
 decltype(auto) increment(int &a)   // auto& increment(int &a)
 {
   ++a;
   return a;   
 }

int p  = 10;
int& y = increment(p);
cout << y <<endl;

-----------------------------------------------
  const int x = 10;
  auto y = x; // int
decltype(auto) y = x; // const int

int&& z = 10;
auto x = std::move(z);  // int
decltype(auto) x = std::move(z); // int&&

//=================================================================
// 3. Digit Separator
// =================================================================
// 100,000
    int m = 100000;

    int n = 100'000;

    cout << m << endl;
    cout << n <<endl;

// ======================================================================
// 4. Binary Literal
// =================================================================
    int c = 0xFF;  //till C++11

    int b = 0b11111111; // C++14

    cout << c << "    " << b <<endl;

// =================================================================
// 5. Deprecated keyword in C++
// ============================================================
   [[deprecated("This function will be replaced with add template")]]
    int add(int i, int j)
    {
        return i+j;
    }

// ================================================================
// 6. variable template
// ==================================================================
    template <typename T>
    T pi = T(3.141598765436745382262L);

    std::cout << pi<int> <<endl;
    std::cout << pi<float> <<endl;
    std::cout << pi<double> <<endl;
    std::cout << pi<long double> <<endl;
