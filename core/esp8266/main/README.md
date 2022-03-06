# ESP8266 Source code 
## How to run?

> You must upload the code on the esp8266 its self. THIS DOESN'T GO ON THE ARDUINO ITSSELF
> Also Data includes all HTML/CSS files and folders.


Run the following commands on linux/osx. in this directory
```
touch credits.h
cat credits.h >>     "#ifndef STASSID
    #define STASSID "WIFINAME"
    #define STAPSK  "WIFIPASS"
    #endif

    #ifndef STUNAME
    #define STUNAME "userLogin"
    #define STUOASS "userPassword"
    #endif"

    #ifndef UTCOFFSET
    #define UTCOFFSET seconds
    #endif
```

Change all the values.

## Windows
Create `credits.h`
Copy
```
    #ifndef STASSID
    #define STASSID "WIFINAME"
    #define STAPSK  "WIFIPASS"
    #endif

    #ifndef STUNAME
    #define STUNAME "userLogin"
    #define STUOASS "userPassword"
    #endif

    #ifndef UTCOFFSET
    #define UTCOFFSET seconds
```
And then change the values.

# How does it work? 
> The code is well documented using commends

all tests to write the code are written in the ./examples/ directory. And all HTML/CSS/JS front-end are written in pages. /website is a different. 