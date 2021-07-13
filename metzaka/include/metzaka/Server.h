#pragma once

#include <metzaka/Session.h>
#include <metzaka/CmdHandler.h>
#include <memory>
#include <boost/asio.hpp>

class server
{
public:
  server(boost::asio::io_context& io_context, int port)
    : acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
  {
    do_accept();
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket)
        {
          if (!ec)
          {
            std::make_shared<session>(std::move(socket))->start();
          }

          do_accept();
        });
  }

  boost::asio::ip::tcp::acceptor acceptor_;
};