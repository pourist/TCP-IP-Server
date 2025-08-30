#include "TcpServerController.hpp"
#include "config_temp/temp_pars_config.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv){
    try{
        RuntimeConfig cfg;
        parseTempConfig(argc, argv, cfg);

        

    }
    catch (std::exception &e){
        std::cerr << "Error:\t" << e.what() << std::endl;
    }
    return 0;
}