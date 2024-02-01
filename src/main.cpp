#include "ConsoleMenu.hpp"
#include "CommandInitializer.hpp"
#include "App.hpp"
#include <iostream>
#include <string>
#include "IMenu.hpp"

int main()
{
    // Initializes commands and app components.
    CommandInitializer initializer;
    // Starts the application.
    initializer.init(initializer);

    return 0;
}