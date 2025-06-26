//
// Created by kyriakum on 26/6/2025.
//

#ifndef LOGGING_H
#define LOGGING_H

#include <spdlog/spdlog.h>

#define LOG_INFO(...) spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
#define LOG_DEBUG(...) spdlog::debug(__VA_ARGS__)

#endif //LOGGING_H
