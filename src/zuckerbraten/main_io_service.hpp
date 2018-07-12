#ifndef HOPMOD_MAIN_IO_SERVICE_HPP
#define HOPMOD_MAIN_IO_SERVICE_HPP

#include <asio/high_resolution_timer.hpp>
#include <asio.hpp>

asio::io_service & get_main_io_service();

#endif
