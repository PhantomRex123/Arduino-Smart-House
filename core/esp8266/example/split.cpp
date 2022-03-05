#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string str = "ANTMOIST=1;MOISTION=0;CLAP=1;ESPCAM=0;ESPSESSIONID=1;";
  string arr[10];
  int i = 0;
  stringstream ssin(str);
  while (ssin.good() && i < 10)
  {
    ssin >> arr[i];
    ++i;
  }
  for (i = 0; i < 10; i++)
  {
    if (arr[i] == "ANTMOIST=1;") {
      std::cout << arr[i] << std::endl;
      break;
    }
  }
}


int main()
{
  string str = "LANTMOIST=1; MOISTION=0; CLAP=1; ESPCAM=0; ESPSESSIONID=1";
  removeDupWord(str, "MOISTION=");
  return 0;
}