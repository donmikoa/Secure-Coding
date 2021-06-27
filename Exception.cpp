// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
    //Throw any standard exception
    try {
        std::cout << "Running Even More Custom Application Logic." << std::endl;
        return true;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}
void do_custom_application_logic()
{
    // Wraped the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    //Implementing a try/catch
    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (std::exception& e) {
        // Throw a custom exception derived from std::exception
        //  and catch it explictly in main
        std::cout << "Leaving Custom Application Logic." << e.what() << std::endl;
    }
     

}

float divide(float num, float den)
{
    // Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    if (den == 0) {
        throw "Division by zero error!";
    }
    return (num / den);
}

void do_division() noexcept
{
    // created an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (...) {
        std::cout << "Exception caught when carrying out the divide function" << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try{
        do_division();
        do_custom_application_logic();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        throw "Error found";
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu