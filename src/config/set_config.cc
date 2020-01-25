#include <releax/config.hh>

int
Config::set(std::string variable,
            std::string value)
{
    /*
    std::ifstream infile(this->filename);
    if (!infile.good()) {
        return -5;
    }
    std::ofstream outfile(this->filename + ".new");
    if (!infile.good()) {
        return -6;
    }

    std::string line;
    bool varfound = false;
    for (auto a = getline(infile, line) != 0) {
        if (line.find("=") != line.npos) {
            if (!varfound) {
                std::string tmp_var = this->trim(line.substr(0,line.find("=")));
                if (tmp_var == variable) {
                    std::string input_line = variable + " = " + value;
                    outfile.write(input_line.c_str(),input_line.size());
                    varfound = true;
                } else {
                    outfile.write(line.c_str(),line.size());
                }
            } else {
                outfile.write(line.c_str(),line.size());
            }

        }
        
    }

    if (!varfound) {
        std::string input_line = variable + " = " + value;
        outfile.write(input_line.c_str(),input_line.size());
    }

    outfile.close();
    infile.close();

    filesys::copy(this->filename, this->filename + ".old");
    filesys::copy(this->filename + ".new", this->filename);
    */
    return 0;
}