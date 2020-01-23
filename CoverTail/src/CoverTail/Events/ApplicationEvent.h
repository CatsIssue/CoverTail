#pragma once

#include "Event.h"
#include <sstream>

namespace CoverTail
{
	class CoreTail_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Height; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resize Event: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class CoreTail_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class CoreTail_API AppTick : public Event
	{
	public:
		AppTick() {}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	
	class CoreTail_API AppTick : public Event
	{
	public:
		AppTick() {}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class CoreTail_API AppRenderer : public Event
	{
	public:
		AppRenderer() {}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}