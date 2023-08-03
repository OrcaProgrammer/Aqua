#pragma once

#include <Windows.h>

#include <iostream>
#include <string>
#include <chrono>
#include <format>

#include "Core.h"

class AQUA_API Logger
{
public:

	template <typename... Args>
	static void Log(const char* prefix, Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		std::cout << prefix << std::format("{:%X}", time) << " LOG:\t\t";

		(std::cout << ... << args) << "\n";
	};

	template <typename... Args>
	static void Trace(const char* prefix, Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		std::cout << prefix << std::format("{:%X}", time) << " TRACE:\t\t";

		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

	template <typename... Args>
	static void Info(const char* prefix, Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		std::cout << prefix << std::format("{:%X}", time) << " INFO:\t\t";

		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

	template <typename... Args>
	static void Warn(const char* prefix, Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		std::cout << prefix << std::format("{:%X}", time) << " WARNING:\t";

		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

	template <typename... Args>
	static void Error(const char* prefix, Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		std::cout << prefix << std::format("{:%X}", time) << " ERROR:\t\t";

		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};
};


#ifdef _DEBUG
	#define AQ_LOG(...) Logger::Log("AQUA\t\t", __VA_ARGS__)
	#define AQ_TRACE(...) Logger::Trace("AQUA\t\t", __VA_ARGS__)
	#define AQ_INFO(...) Logger::Info("AQUA\t\t", __VA_ARGS__)
	#define AQ_WARN(...) Logger::Warn("AQUA\t\t", __VA_ARGS__)
	#define AQ_ERROR(...) Logger::Error("AQUA\t\t", __VA_ARGS__)

	#define AQ_DEBUG_LOG(...) Logger::Log("AQUA (DEBUG)\t", __VA_ARGS__)
	#define AQ_DEBUG_TRACE(...) Logger::Trace("AQUA (DEBUG)\t", __VA_ARGS__)
	#define AQ_DEBUG_INFO(...) Logger::Info("AQUA (DEBUG)\t", __VA_ARGS__)
	#define AQ_DEBUG_WARN(...) Logger::Warn("AQUA (DEBUG)\t", __VA_ARGS__)
	#define AQ_DEBUG_ERROR(...) Logger::Error("AQUA (DEBUG)\t", __VA_ARGS__)
#else
	#define AQ_LOG(...) Logger::Log("AQUA\t", __VA_ARGS__)
	#define AQ_TRACE(...) Logger::Trace("AQUA\t", __VA_ARGS__)
	#define AQ_INFO(...) Logger::Info("AQUA\t", __VA_ARGS__)
	#define AQ_WARN(...) Logger::Warn("AQUA\t", __VA_ARGS__)
	#define AQ_ERROR(...) Logger::Error("AQUA\t", __VA_ARGS__)

	#define AQ_DEBUG_LOG(...)
	#define AQ_DEBUG_TRACE(...)
	#define AQ_DEBUG_INFO(...)
	#define AQ_DEBUG_WARN(...)
	#define AQ_DEBUG_ERROR(...)
#endif