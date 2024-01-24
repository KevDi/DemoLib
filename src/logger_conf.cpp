#include "logger/logger_conf.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

std::shared_ptr<spdlog::logger> setup_logger(std::vector<spdlog::sink_ptr> sinks) {
    auto logger = spdlog::get("LogAndConfigLogger");
    if (!logger) {
        if (sinks.size() > 0) {
            logger = std::make_shared<spdlog::logger>("LogAndConfigLogger", std::begin(sinks), std::end(sinks));
            spdlog::register_logger(logger);
        } else {
            logger = spdlog::stdout_color_mt("LogAndConfigLogger");
        }
    }

    return logger;
}