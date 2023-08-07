#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <format>

#include "Simulator/UI/ConsoleUI.h"

class Logger
{
public:

	static void Log(const char* prefix, std::string msg) {

		std::string output;

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		output.append(prefix);
		output.append(std::format("{:%X}", time));
		output.append("\tLOG:\t\t");
		output.append(msg);

		ConsoleLine newLine;
		newLine.text = output;
		newLine.color = ImVec4(255.0f, 255.0f, 255.0f, 255.0f);

		ConsoleUI::AddLine(newLine);
	};


	static void Trace(const char* prefix, std::string msg) {

		std::string output;

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		output.append(prefix);
		output.append(std::format("{:%X}", time));
		output.append("\tTRACE:\t\t");
		output.append(msg);

		ConsoleLine newLine;
		newLine.text = output;
		newLine.color = ImVec4(42.0f, 168.0f, 46.0f, 255.0f);

		ConsoleUI::AddLine(newLine);
	};


	static void Info(const char* prefix, std::string msg) {

		std::string output;

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		output.append(prefix);
		output.append(std::format("{:%X}", time));
		output.append("\tINFO:\t\t");
		output.append(msg);

		ConsoleLine newLine;
		newLine.text = output;
		newLine.color = ImVec4(30.0f, 138.0f, 232.0f, 255.0f);

		ConsoleUI::AddLine(newLine);
	};

	
	static void Warn(const char* prefix, std::string msg) {

		std::string output;

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		output.append(prefix);
		output.append(std::format("{:%X}", time));
		output.append("\tWARN:\t\t");
		output.append(msg);

		ConsoleLine newLine;
		newLine.text = output;
		newLine.color = ImVec4(226.0f, 226.0f, 40.0f, 255.0f);

		ConsoleUI::AddLine(newLine);
	};


	static void Error(const char* prefix, std::string msg) {

		std::string output;

		auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
		output.append(prefix);
		output.append(std::format("{:%X}", time));
		output.append("\tERROR:\t\t");
		output.append(msg);

		ConsoleLine newLine;
		newLine.text = output;
		newLine.color = ImVec4(226.0f, 40.0f, 40.0f, 255.0f);

		ConsoleUI::AddLine(newLine);
	};
};


#ifdef _DEBUG
	#define AQ_LOG(msg)			Logger::Log("AQUA\t\t\t", msg)
	#define AQ_TRACE(msg)		Logger::Trace("AQUA\t\t\t", msg)
	#define AQ_INFO(msg)		Logger::Info("AQUA\t\t\t", msg)
	#define AQ_WARN(msg)		Logger::Warn("AQUA\t\t\t", msg)
	#define AQ_ERROR(msg)		Logger::Error("AQUA\t\t\t", msg)

	#define AQ_DEBUG_LOG(msg)	Logger::Log("AQUA (DEBUG)\t", msg)
	#define AQ_DEBUG_TRACE(msg) Logger::Trace("AQUA (DEBUG)\t", msg)
	#define AQ_DEBUG_INFO(msg)	Logger::Info("AQUA (DEBUG)\t", msg)
	#define AQ_DEBUG_WARN(msg)	Logger::Warn("AQUA (DEBUG)\t", msg)
	#define AQ_DEBUG_ERROR(msg) Logger::Error("AQUA (DEBUG)\t", msg)
#else
	#define AQ_LOG(msg)			Logger::Log("AQUA\t", msg)
	#define AQ_TRACE(msg)		Logger::Trace("AQUA\t", msg)
	#define AQ_INFO(msg)		Logger::Info("AQUA\t", msg)
	#define AQ_WARN(msg)		Logger::Warn("AQUA\t", msg)
	#define AQ_ERROR(msg)		Logger::Error("AQUA\t", msg)

	#define AQ_DEBUG_LOG(msg)
	#define AQ_DEBUG_TRACE(msg)
	#define AQ_DEBUG_INFO(msg)
	#define AQ_DEBUG_WARN(msg)
	#define AQ_DEBUG_ERROR(msg)
#endif