#pragma once
#include "Dependencies.hpp"

namespace GUI
{
	class Drawable;

	class GUI_API Window : public sf::RenderWindow
	{
	public:
		void draw(Drawable& drawable);

	};

	class GUI_API LogBase
	{
	protected:
		std::ostream* logger;


	public:
		typedef void (*Callback)(std::ostream&);
		Callback success, successEnd;
		Callback info, infoEnd;
		Callback warning, warningEnd;
		Callback error, errorEnd;
		Callback def, defEnd; //default

		void setLogger(std::ostream& out);
		void setSuccessCallback(Callback callback);
		void setSuccessEndCallback(Callback callback);
		void setInfoCallback(Callback callback);
		void setInfoEndCallback(Callback callback);
		void setWarningCallback(Callback callback);
		void setWarningEndCallback(Callback callback);
		void setErrorCallback(Callback callback);
		void setErrorEndCallback(Callback callback);
		void setDefaultCallback(Callback callback);
		void setDefaultEndCallback(Callback callback);
		void setDefaultLogger(); // this is btw cout
	};

	class GUI_API Drawable
	{
	public:
		virtual void draw(Window& window);
	};

	class GUI_API FontRegistry : public LogBase
	{
	public:
		enum class Status
		{
			FileNotFound,
			UnknownError
		};
		Status registerFont()
	};
}