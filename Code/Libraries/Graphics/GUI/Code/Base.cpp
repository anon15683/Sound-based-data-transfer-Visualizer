#include <GUI/Base.hpp>
#include <iostream>

void GUI::Drawable::draw(Window& window)
{

}

void GUI::Window::draw(Drawable& drawable)
{

}

std::ostream& GUI::operator<<(std::ostream& out, GUI::LogBase::Manipulator level)
{
	switch (level)
	{
	case GUI::LogBase::Success:
		break;
	case GUI::LogBase::Default:
		break;
	case GUI::LogBase::Info:
		break;
	case GUI::LogBase::Warning:
		break;
	case GUI::LogBase::Error:
		break;
	default:
		break;
	}
	return out;
}

GUI::FontRegistry::Status GUI::FontRegistry::registerFont(std::string font, std::string path)
{
	sf::Font* fontptr = new sf::Font;
	if (!fontptr->openFromFile(path))
	{
		delete fontptr;
		return Status::FileNotFound;
	}
	fonts[font] = fontptr;
	return Status::Success;
}

GUI::FontRegistry::Status GUI::FontRegistry::registerSystemFont(std::string font, std::string path)
{
	sf::Font* fontptr = new sf::Font;
	if (!fontptr->openFromFile("C:\\Windows\\Fonts\\" + path))
	{
		delete fontptr;
		return Status::FileNotFound;
	}
	fonts[font] = fontptr;
	return Status::Success;
}

GUI::FontRegistry::FontRegistry()
{

}

GUI::FontRegistry::~FontRegistry()
{
	for (unsigned int i = 0; i < fonts.size(); i++)
		delete fonts[i];
}
