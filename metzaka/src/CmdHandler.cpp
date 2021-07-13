#include <metzaka/CmdHandler.h>
#include <metzaka/Server.h>
#include <iostream>

cmd_handler::cmd_handler() {

}

void cmd_handler::Run() {
    boost::asio::io_context io_context;

    auto self = shared_from_this();

    server s(io_context, 5300, self);

    io_context.run();
}

void cmd_handler::Handle(boost::asio::mutable_buffer& buffer, session session) {
    std::cout << "Handle cmd: " << buffer << std::endl;
}

