# Museum Project - CSC-237-04
Welcome to the museum! This page is your guide to how this program runs and where to find examples of OOP concepts within the code.

First off, a complete UML diagram is found in the /data directory. 

To view the UML diagram:

    1. Go to https://app.diagrams.net/
    
    2. Click File → Open from → Device
   
    3. Select the .drawio file from the unzipped project folder

This project is structured as follows.

- \Museum
	- /data
		- artworks.csv
		- userCollection.csv
	- /include
		- Artwork.h
		- Date.h
		- Dimension.h
		- Name.h
		- Painting.h
		- Sculpture.h
		- WrittenWord.h
		- Utility.h
	- /src
		- Artwork.cpp
		- Date.cpp
		- Dimension.cpp
		- Name.cpp
		- Painting.cpp
		- Sculpture.cpp
		- WrittenWord.cpp

### Overview

The Museum Management System (MMS) is a simple C++ console app that lets users explore a digital collection of artworks. When the program starts, it tries to load data from CSV files and sorts the artworks into three categories: Paintings, Sculptures, and Written Word. If the files aren’t found or are empty, it falls back on some sample data. The main menu gives a quick summary of what’s available and offers different ways to interact with the collection.

### Features

Users can browse different exhibit types, view all artwork titles, build a personal collection, and check which pieces are the most or least valuable. The program checks for valid input and gives feedback to keep things running smoothly. When the user exits, their collection is saved so it can be loaded again next time. 

### OOP concepts
#### Encapsulation
Each artwork type (Painting, Sculpture, WrittenWord) is a class that encapsulates its properties (like title, date, dimensions, etc.) and behavior (like toString() and value() methods).

#### Abstraction
The Artwork class is an abstract base class that defines the interface (value(), toString()) for all artwork types, without specifying how those functions work.

#### Inheritance
Painting, Sculpture, and WrittenWord all inherit from the Artwork base class.

#### Polymorphism
All artworks are stored as shared_ptr<Artwork> and call virtual functions like toString() or value(), which are resolved at runtime.

### Running the Application
To run the Museum Management System, the source code must be compiled using a C++20-compatible compiler such as g++ or a development environment like Visual Studio. The user can compile the program manually by including all the necessary .cpp files. After compiling, the program can be run from the terminal or command prompt. It reads data from two CSV files located in a folder named data one directory above the executable. These files contain the main artwork collection and the user’s saved collection.
