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
	static void Log(const char* message);
	static void Trace(const char* message);
	static void Info(const char* message);
	static void Warn(const char* message);
	static void Error(const char* message);
private:
	static std::string GetCurrentTime();
};

