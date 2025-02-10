#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#ifdef GUI_EXPORT
#ifdef GUI_EXPLICIT
#define GUI_API extern "C" __declspec(dllexport)
#else
#define GUI_API __declspec(dllexport)
#endif
#else
#define GUI_API __declspec(dllimport)
#endif

#define log (*logger)
