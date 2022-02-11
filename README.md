# Marionkart
A slightly dodgily-formatted C++ script that writes every possible Character/Vehicle stat combination in Mario Kart 8 Deluxe to a CSV. Requires Boost (https://www.boost.org/) for use of  ``boost::tuple``.

When I say 'combo,' I mean the character and vehicle classes that create a unique stat spread. Most, if not all characters, karts, and parts, have a dupe or several dupes, e.g. DK has the same stats as Waluigi and Roy, the Roller tires have the same stats as the Azure Roller tires, and so on.

The Mario Wiki has an in-depth section on these character classes, and how stats work in general: https://www.mariowiki.com/Mario_Kart_8_Deluxe#Drivers'_and_vehicle_parts'_statistics

# Usage
Add it to a new Visual Studio project, and or compile and run. Use your favourite spreadsheet program to manipulate the output CSV to your hearts' content - although, I could update this script to push back combo statistics by default.
