# Museum Project - CSC-237-04

Welcome to the museum! This page is your guide to how this program runs and where to find examples of OOP concepts within the code.

First off, a complete UML diagram is found in the /data directory. 
To view the UML diagram:
    1. Go to https://app.diagrams.net/
    2. Click File → Open from → Device
    3. Select the .drawio file from the unzipped project folder
    
Also found in this directory is artworks.csv. This csv file is used to create the different artworks in the museum. 
When the program starts, artworks.csv is parsed and objects are created and stored in a container. The functions that accomplish this can be found in the main.cpp file.

This project is strucutred as follows.

<pre> Museum/ ├── CMakeLists.txt ├── include/ │ ├── Artwork.h │ ├── Date.h │ ├── Dimensions.h │ ├── Name.h │ ├── Painting.h │ ├── Sculpture.h │ ├── WrittenWord.h ├── src/ │ ├── main.cpp │ ├── Artwork.cpp │ ├── Date.cpp │ ├── Dimensions.cpp │ ├── Name.cpp │ ├── Painting.cpp │ ├── Sculpture.cpp │ ├── WrittenWord.cpp ├── data/ │ └── artworks.csv │ └── Museum-UML.drawio └── README.md </pre>

