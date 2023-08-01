#pragma once

#include <Windows.h>

#include <iostream>
#include <string>
#include <chrono>
#include <format>

#include <Aqua.h>

class AQUA_API Logger
{
public:

	template <typename... Args>
	static void Log(Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << "AQUA " << GetCurrentTime() << " LOG:  \t";
		(std::cout << ... << args) << "\n";
	};

	template <typename... Args>
	static void Trace(Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		std::cout << "AQUA " << GetCurrentTime() << " TRACE:  \t";
		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

	template <typename... Args>
	static void Info(Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		std::cout << "AQUA " << GetCurrentTime() << " INFO:  \t";
		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

	template <typename... Args>
	static void Warn(Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
		std::cout << "AQUA " << GetCurrentTime() << " WARNING:\t";
		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

	template <typename... Args>
	static void Error(Args&&... args) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "AQUA " << GetCurrentTime() << " ERROR:  \t";
		(std::cout << ... << args) << "\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	};

private:

	static std::string GetCurrentTime() {
		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		return std::format("{:%X}", time);
	};
};

