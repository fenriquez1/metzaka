#include <metzaka/CmdHandler.h>
#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "Starting server..." << std::endl;

    cmd_handler handler;
    
    handler.Run();

    return 0;
}