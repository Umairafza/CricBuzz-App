CricBuzz - Cricket Management System
CricBuzz is a comprehensive cricket management system developed as a semester project for the Object-Oriented Programming course at the National University of Computer and Emerging Sciences (FAST-NUCES) in Fall 2022. This C++ application simulates a cricket information platform, allowing users to manage teams, players, matches, and news, with an interactive console interface and a graphical user interface (GUI) built using the SFML library.
Features

Team Management: Add, update, and display team details, including captains, coaches, match statistics, and ICC rankings.
Player Management: Manage player profiles with attributes like name, date of birth, shirt number, average, total runs, and rankings. Supports adding, removing, searching, and updating player records.
Match Scheduling and Tracking: Schedule and conduct matches, specifying teams, dates, venues, match types, and audience status. Display upcoming and recent matches, and update world records and rankings.
News Updates: Provide news on previous and upcoming matches, team rankings, and player rankings, with dynamic data retrieval from text files.
Graphical Interface: Interactive GUI using SFML to visualize team details, player profiles, rankings, and match news, with support for background music and menu navigation.
File Handling: Persistent storage of player, team, match, and ranking data using text files for seamless data management.
Exception Handling: Robust error handling for invalid inputs to ensure smooth user interaction.

Technologies Used

C++: Core programming language for implementing the application logic.
SFML (Simple and Fast Multimedia Library): Used for creating the graphical interface, including menus, images, and text rendering.
File I/O: Utilized for storing and retrieving data in text files.
Object-Oriented Programming: Implemented using classes, inheritance, and encapsulation for modular and reusable code.

Project Structure

CricBuzz.h: Header file defining the Team, Player, Match, and News classes, along with supporting structures and enums.
CricBuzz.cpp: Source file containing the implementation of class methods for managing teams, players, matches, and news.
main.cpp: Entry point of the application, handling user authentication, console-based menu navigation, and SFML-based GUI rendering.

How to Run

Prerequisites:

Install a C++ compiler (e.g., g++ or Visual Studio).
Install the SFML library and configure it in your development environment.
Ensure the required font file (OpenSans-Bold.ttf) and audio file (Y2Mate.ogg) are in the project directory.
Place the image files (e.g., Login.png, Pakistan.png, etc.) in the project directory for the GUI.


Compilation:

Compile the code using a C++ compiler with SFML linked:g++ -c main.cpp CricBuzz.cpp
g++ main.o CricBuzz.o -o CricBuzz -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio




Execution:

Run the executable:./CricBuzz


Use the console menu to interact with the system or press the right shift key to start the SFML-based GUI.
Navigate the GUI using keyboard keys (e.g., P for Pakistan team, R for rankings, Space to play music).



Usage

Console Interface:

Log in or sign up to access the system.
Choose from four main classes: Team, Player, Matches, or News.
Perform operations like adding players, scheduling matches, or viewing news using the menu-driven interface.
Press s to exit the console interface.


Graphical Interface:

Press Right Shift to start the GUI.
Use keys like F1 for team menu, F3 for news menu, or P, I, E, N, B to view specific team details.
View rankings, world records, and match details using keys like R, W, C, or V.
Control background music with Space (play) and Num0 (pause).



Sample Output
The application provides both console and graphical outputs:

Console: Displays team details, player stats, match schedules, and news in a structured format.
SFML GUI: Renders team profiles, rankings, and match news with images and text, offering an interactive experience.

Limitations

File-based storage may not scale for large datasets.
Limited error handling for file access issues.
GUI navigation relies heavily on keyboard inputs, which may not be intuitive for all users.

Future Improvements

Implement a database for efficient data storage and retrieval.
Enhance the GUI with mouse-based navigation and more interactive elements.
Add real-time match simulation features.
Improve error handling for file operations and user inputs.

Contributors

Umair Afzal (21F-9612, BCS-3D)
Lab Instructor: Hannan Farooq
Course Instructor: Asif Ameer

Acknowledgments
This project was developed as part of the Object-Oriented Programming course at FAST-NUCES in Fall 2022. Special thanks to the instructors for their guidance and support.
