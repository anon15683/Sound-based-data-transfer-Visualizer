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
	public:
		enum Manipulator
		{
			Success,
			Info,
			Warning,
			Error,
			Default
		};
		enum LogLevel
		{
			Success,
			Info,
			Warning,
			Error,
			Default
		};
	protected:
		std::ostream* logger;
		friend std::ostream& operator<< (std::ostream& out, Manipulator level);

	public:

		
	};

	class GUI_API Drawable
	{
	public:
		virtual void draw(Window& window);
	};

	class GUI_API FontRegistry : public LogBase
	{
		std::unordered_map<std::string, sf::Font*> fonts;
	public:
		enum class Status
		{
			Success = 0,
			FileNotFound = 1,
			UnknownError = 2
		};

		Status registerFont(std::string font, std::string path);
		Status registerSystemFont(std::string font, std::string path);

		FontRegistry();
		~FontRegistry();
	};
}