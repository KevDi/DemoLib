#include "logandconfig/converter.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <iostream>

int Converter::conv() const {
    auto lg = spdlog::get("LogAndConfigLogger");
    if (lg) {
        lg->info("Lib Logging");
    } else {
        std::cout << "No Logger!\n";
    }
    return 42;
}

void Converter::register_logger(std::shared_ptr<spdlog::logger> logger) {
    spdlog::register_logger(logger);
}