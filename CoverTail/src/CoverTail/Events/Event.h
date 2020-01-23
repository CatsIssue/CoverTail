#pragma once

#include "CoverTail/Core.h"

#include <string>
#include <functional>


namespace CoverTail
{
	 // Event are now blocking, i.e dispatched immediately
	 // In the future better if event go to buffer and in turning 
	 // processed

	// Different kind of Event types
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowRelease, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRenderer,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),

	};

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; } \
								virtual EventType GetEventType() const override { return GetStaticType(); } \
								virtual const char* GetName() const override { return #type; }

	class CoreTail_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool isInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected: 
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template <typename T> 
		using EventFn = std::function<bool(T&)>; // can be any Event

	public: 
		EventDispatcher(Event& event)
			: m_Event(event) {} 

		template <typename T> 
		bool Dispatch(EventFn<T> func)
		{
			if (m_EventGetEventType == T::GetStaticType())
			{
				m_event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	 };

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}