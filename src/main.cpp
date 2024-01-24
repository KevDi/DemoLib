#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/win_eventlog_sink.h>
#include <spdlog/spdlog.h>

#include <filesystem>
#include <iostream>
#include <logandconfig/converter.hpp>
#include <logger/logger_conf.hpp>
#include <sstream>
#include <string>
#include <toml++/toml.hpp>

struct Pipeline {
    std::string name;
};

int main() {
    toml::table tbl;
    try {
        tbl = toml::parse_file("config.toml");
        std::cout << tbl["data"] << '\n';
        toml::array* pipes = tbl["data"].as_array();
        pipes->for_each([](toml::table& ele) {
            std::cout << ele << '\n';
        });

    } catch (const toml::parse_error& error) {
        std::cout << error << '\n';
    }

    return 0;
}