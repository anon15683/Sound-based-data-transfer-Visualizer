#include <GUI/Base.hpp>
#include <iostream>

void GUI::Drawable::draw(Window& window)
{

}

void GUI::Window::draw(Drawable& drawable)
{

}

void GUI::LogBase::setLogger(std::ostream& out)
{
	logger = &out;
}

void GUI::LogBase::setSuccessCallback(Callback callback)
{
	success = callback;
}

void GUI::LogBase::setDefaultLogger()
{
	logger = &std::cout;
}
