#include <iostream> 
int main()
{
  char* object[2][2] = {{"relay", "on"}, {"relay2", "off"}};
  // DynamicJsonDocument doc(1024);
  // for (int i = 0; i < sizeof(object) / sizeof(object[0]); i++)
  // {
  //   for (int j = 0; j < sizeof(object[i]) / sizeof(object[i][0]); j++)
  //   {
  //     std::cout << object[i][j]  << " = " << std::endl;
  //     ++j;
  //     std::cout  << object[i][j] << std::endl;
  //     // doc[object[i][j]] = object[i][++j];
  //   }
  // }

    for (int i = 0; i < sizeof(object) / sizeof(object[0]); i++)
  {
    for (int j = 0; j < sizeof(object[i]) / sizeof(object[i][0]); j++)
    {
      std::cout << object[i][j]  << " = " << object[i][++j] << std::endl;
      // ++j;
    }
  }
}