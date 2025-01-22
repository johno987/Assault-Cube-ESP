# Assault Cube ESP

Welcome to the **Assault Cube ESP** project! This repository contains the source code and instructions for creating an interna; ESP (Extra Sensory Perception) tool for the open-source first-person shooter game, **Assault Cube**.

## Features

- **Player ESP**: Displays player locations, health, and other information.
- **Traceline**: Displays a traceline from the origin of the window to the centroid of the enemy's bounding box.
- **Performance Optimisations**: Ensures minimal performance impact on the game.

## Requirements

To build and run this project, you will need:

- **Windows OS**: Compatible with Windows 10/11.
- **Visual Studio**: Preferred IDE for compiling the project.
- **C++ Compiler**: Required for building the project.
- **Assault Cube**: Installed and running on your system.

## Setup

### 1. Clone the Repository
```bash
git clone https://github.com/johno987/Assault-Cube-ESP.git
cd Assault-Cube-ESP
```

### 2. Install Dependencies
- Download and install the [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812).
- Ensure Visual Studio is installed with the Desktop Development with C++ workload.

### 3. Open the Project
- Open the `.sln` file in Visual Studio.
- Configure the project build settings (Release/Debug).

### 4. Build the Project
- Build the solution (`Ctrl + Shift + B`).
- Ensure there are no errors during the build process.

### 5. Run the ESP
- Launch Assault Cube.
- Inject the compiled DLL.
- Enjoy enhanced gameplay with ESP overlays!

## Usage

- Ensure that the tool is running while Assault Cube is open.
- Inject the DLL into the games process
- Press F1 to set your health and ammo to 5000
- Press insert to enable the swapBuffersHook and ESP
- Press DEL to disable the ESP and unhook the swapBuffers function

## Disclaimer

This project is for educational purposes only. Using ESP or other game modifications may violate the terms of service of the game. The author does not condone cheating or exploiting in multiplayer games. Use this project responsibly.


## Acknowledgments

- Special thanks to the developers of Assault Cube for creating a great open-source FPS game.
- Inspiration from various game-hacking communities and resources.
