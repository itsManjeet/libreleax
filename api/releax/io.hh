#include <iostream>

namespace color {
    enum code {

        reset         = 0,
        bold          = 1,
        underline     = 4,
        inverse       = 7,
        bold_off      = 21,
        underline_off = 24,
        inverse_off   = 27,

        fg_black      = 30,
        fg_red,
        fg_green,
        fg_yellow,
        fg_blue,
        fg_magenta,
        fg_cyan,
        fg_white,

        bg_black       = 40,
        bg_red,
        bg_green,
        bg_yellow,
        bg_blue,
        bg_magenta,
        bg_cyan,
        bg_white
    };

}

namespace io {
    std::string set(color::code tcode);
    std::string err();
    std::string proc();
    std::string msg();
    std::string warn();
    std::string end();
}