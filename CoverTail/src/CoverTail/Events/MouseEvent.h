#pragma once

#include "Event.h"
#include <sstream> 

namespace CoverTail
{
	class CoreTail_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}


		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Event " << m_MouseX << " , " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	class CoreTail_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() { return m_XOffset; }
		inline float GetYOffset() { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Offset " << m_XOffset << " , " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class CoreTail_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public: 

		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {} 

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class CoreTail_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
		EVENT_CLASS_CATEGORY(EventCategoryInput)
	private:
		int m_Button;
	};
}
