#include <releax/releax.hh>

osinfo::osinfo_t
osinfo::get_info()
{
    auto cfg = new Config(OS_INFO_FILE);

    osinfo_t info_struct;
    info_struct.name    = cfg->get("NAME",DEFAULT_OS_NAME);
    info_struct.version = strtod(cfg->get("VERSION").c_str(),0);
    std::string release_code = cfg->get("VERSION_CODENAME",DEFAULT_OS_VER_CODENAME);

         if (release_code == "beta")   info_struct.release = beta_release;
    else if (release_code == "alpha")  info_struct.release = alpha_release;
    else if (release_code == "stable") info_struct.release = stable_release;
    else                               info_struct.release = unknown_release;

    info_struct.id          = cfg->get("ID",DEFAULT_OS_ID);
    info_struct.pretty_name = cfg->get("PRETTY_NAME",DEFAULT_OS_NAME);
    info_struct.version_id  = cfg->get("VERSION_ID");
    info_struct.home_url    = cfg->get("HOME_URL");

    return info_struct;
}