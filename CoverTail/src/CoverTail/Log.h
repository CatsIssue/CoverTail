#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace CoverTail
{
	class CoreTail_API Log
	{
	public: 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log macros
#define CT_CORE_TRACE(...)    ::CoverTail::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CT_CORE_INFO(...)     ::CoverTail::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CT_CORE_WARN(...)     ::CoverTail::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CT_CORE_ERROR(...)    ::CoverTail::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CT_CORE_CRITICAL(...) ::CoverTail::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define CT_TRACE(...)         ::CoverTail::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CT_INFO(...)          ::CoverTail::Log::GetClientLogger()->info(__VA_ARGS__)
#define CT_WARN(...)          ::CoverTail::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CT_ERROR(...)         ::CoverTail::Log::GetClientLogger()->error(__VA_ARGS__)
#define CT_CRITICAL(...)      ::CoverTail::Log::GetClientLogger()->critical(__VA_ARGS__)