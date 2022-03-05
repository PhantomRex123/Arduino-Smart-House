// THIS IS FOR TESTING PERPOUSES!
// #include <*> lol never tried it though :(
#include <cstring>
#include <iostream>

int main()
{
char cookies[] = "test=1;test2=2";
char* cookie;
char* remaining = cookies;
while (cookie = strtok_r(remaining, ";", &remaining))
    std::cout << cookie << std::endl;
  return 0;
}