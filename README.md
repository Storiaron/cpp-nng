# cpp-nng-homework

## Table of Contents
- [How to Use](#how_to_use)
- [Overview](#overview)

## How to Use <a name="how_to_use"></a>
a. With MSVC installed: 
1. Clone the repository.
2. Build the project.
3. Run the project.

b. Without MSVC installed:
1. Download the latest release.
2. Place the .mid file on the same folder level as the .exe.
3. Run the exe.

## Overview
When the program starts main sets the locale settings to hungarian to match the input data (mingw doesn't support this way, only MSVC). 
After that it creates all the necessary dependencies the application needs, and creates an instance of the  Application class. This class' run method will then call FileReader to get the raw data, 
call the DataStreetInfoMapper that will create Streetname(and type) - hous numbers pairs, which are then passed to DuplicateFinder that finds the duplicate numbers, which are then placed inside an even duplications
and odd duplications string. The application the calls Logger to log out these 2 strings.
Streets without names or streets with matching names are currently calculated as being the same, but the way the code is separated it should be easy to change if needed.
