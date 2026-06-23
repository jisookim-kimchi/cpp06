std::fixed forces normal decimal notation

std::setprecision(1) how many digist are shown.

namespace : to avoid conflict with other function name or variable name

reinterpret_cast  
: Ignore the original type of this memory, take the raw 0s and 1s, and interpret them exactly as this completely different type.  

static cast  
: related type conversion
  1. Truncating floating-point numbers to integers (double to int).
  2. Converting scoped enums (enum class) to integers.
  3. Safe upcasting (moving from a Derived class pointer to a Base class pointer).

Dynamic cast  
: It is used to check at runtime which specific child class a parent class pointer is actually pointing to, allowing you to perform a safe Downcasting.

catch (...){} : catch everything.

reference casting must use 'try/catch'