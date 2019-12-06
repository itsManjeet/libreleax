#ifndef RELEAX_HH
#define RELEAX_HH

#include <bits/stdc++.h>

class error {
public:
    int         status;
    std::string message;

    error(int         status,
          std::string message);
};
#endif