#ifndef RELEAX_HH
#define RELEAX_HH

#include <bits/stdc++.h>
#include <releax/config.hh>
#include <releax/filesys.hh>

#define OS_INFO_FILE "/etc/os-release"

#define DEFAULT_OS_NAME         "releax"
#define DEFAULT_OS_VERSION      0.2
#define DEFAULT_OS_VER_CODENAME "beta"
#define DEFAULT_OS_ID           "releax"


namespace osinfo {
    typedef enum {
        alpha_release,
        beta_release,
        stable_release,
        unknown_release
    } release_t;
    
    typedef float version_t;

    typedef struct {
        std::string name,
                    id,
                    pretty_name,
                    version_id,
                    home_url,
                    version_code;
        
        version_t   version;
        release_t   release;
    } osinfo_t ;

    osinfo_t get_info();
}

#endif