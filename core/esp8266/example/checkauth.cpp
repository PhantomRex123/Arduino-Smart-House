// DEPRECATED. IF FIXED WILL BE IMPLEMENTED 

#include "iostream"
#include "bool"
bool main() {
    unsigned char hupass[20] = "dGVzdGluZwo=";
    unsigned char dupass[20];
    // ESPSESSIONID=1; PASSWORD=aBASE64
    String cookie = "ESPSESSIONID=1; PASSWORD=" + "dGVzdGluZwo=";
    char *cookieV = strtok(cookie, ";");
    if (cookieV.indexOf("ESPSESSIONID=1") != -1) {
      cookieV = strtok(NULL, ";");
      char* base64Decode = decode_base64(hupass, dupass);
      if (cookieV.indexOf(cookieV + (char *)base64Decode) != -1)) {
        return true
      }
    }
  return false;
}