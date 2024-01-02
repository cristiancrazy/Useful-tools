# Useful tools

![mostly used language](https://img.shields.io/github/languages/top/cristiancrazy/Useful-tools)
![last commit](https://img.shields.io/github/last-commit/cristiancrazy/Useful-tools)
![last release](https://img.shields.io/github/v/release/cristiancrazy/Useful-tools)
![licence](https://img.shields.io/github/license/cristiancrazy/Useful-tools)

**This repo contains some useful tools, written in Java/C++/C.**

## Fifth publishing (January 2024)
Added Wine App for Rootlet authentication.
### ***WINE APP FOR DESKTOP (INDIPENDENT APP)***
Required to all Collaborator's user which would use advanced 2FA Rootlet
services. The Android app could be found directly on the <a href="https://rootlet.it/auth">login page</a>,
looking down on the page footer (access with "*Smartcard*")

**IMPORTANT: JRE (or JDK for developers) version 17 is REQUIRED to run the app**

**IMPORTANT: 1. Unzip compressed archive; 2. Run the bash script under /bin folder (or .sh on linux/mac) to start the app.**

**NOTE: The source code is currently private to prevent and avoid security breaches or issues.**

![WineApp 1 0](https://github.com/cristiancrazy/Useful-tools/assets/49765306/ab0daf20-8898-4de3-94bb-6d2b80422450)

## Fourth publishing (June 2022)
Added Arduino based **IR Powerpoint Clicker**.
### ***ARDUINO IR CLICKER (TOOL 4)***
**Control your Powerpoint slide presentation with an IR Remote**

If you have to present a Powerpoint project, this allows you to be more flexible, leaving the computer area, and controlling remotely your presentation. I have tested personally the sketch during an italian school's project, and It was a success. The sketch allows you to bind more keys than the four already defined.

**IMPORTANT: *Remember to bind in the source code your IR codes***
| Macro Defined     |  Bound Key      |
|-------------------|:---------------:|
| BEGIN_PPT         |        F5       |
| EXIT_PPT          |       ESC       |
| PREVIOUS_SLIDE    |  LEFT-ARROW     |
| NEXT_SLIDE        | RIGHT-ARROW     |
******************************************************************

## Third publishing (April 2022)
Small update of the previous published version.
### ***EEPROM TOOLS (TOOL 3)***
**Flash/Read/Erase AT24Cxxx I2C Series EEPROM**

![Tool3](https://user-images.githubusercontent.com/49765306/161352512-9dec3473-753e-42c0-8737-a5a4a4d159bc.PNG)

When you have to save a state or a value permanently, you could use a flash memory or an EEPROM.
Some MCUs prototyping boards could have a built-in EEPROM (Commonly 1 KB for Arduino's boards).
Unlike the built-in EEPROM, you could use instead an I2C EEPROM.
This sketch allows you to check and write data on the external EEPROM (***series AT24Cxxx***).
******************************************************************

## Second publishing (February 2022)
Small update of the previous published version.
### ***IP Network Checker (TOOL 2)***
**Check if the IPs are in the right network**

![Net Checker](https://user-images.githubusercontent.com/49765306/155028617-0d3bc08e-bb4f-4520-ac90-faa50e68fc9d.PNG)

You should insert a valid IP and a valid Subnet Mask. This program will return 
the network ip (net name), and the broadcast ip address.
This is a restyle of an old application that I deployed at the of November, but I've never published it.
This tool is intended for educational purposes (because is a bit poor of functionality).
If you're an expert, obviously, you should avoid this tool.
******************************************************************

## First publishing (December 2021)

 _It's my first, personal, public repository on GitHub, but I_
 _have already contributed on a number of other public repository._

### ***VCMT-RAND (TOOL 1)***

**Generate a vector or a square matrix of integer/double and export it on a .csv file.**

![Tool1](https://user-images.githubusercontent.com/49765306/144744198-8dacedb8-6690-4d40-8ee4-bb761c5f6768.PNG)

You can set the range of the number generated, the separator type(; or ,)
and you are also allowed to choose to overwrite or append the results at the end of the file.  
*You will find this tool under the folder "Rand CSV Generator".*

**This tool uses a lot of RAM during the results generation.**

| Tool 1 Features   |      State      |
|-------------------|:---------------:|
| App feedback | ✔️|
| Base functionality| ✔️|
| Single-line generator| ✔️|
| Multi-line generator | ✔️|
| Works with -(x) values (INTs MODE)| ✔️|
| customized user settings | ✔️|
******************************************************************
