#pragma once

#include <metzaka/Server.h>
#include <metzaka/Session.h>
#include <iostream>
#include <memory>
#include <boost/asio/buffer.hpp>

class cmd_handler : public std::enable_shared_from_this<cmd_handler>
{
public:
    cmd_handler();
    ~cmd_handler() = default;

    void Handle(boost::asio::mutable_buffer& buffer, session session) {
        std::cout << "Handle cmd! " << std::endl;
    }

    void Run() {
        boost::asio::io_context io_context;

        server s(io_context, 5300);

        io_context.run();
    }

};