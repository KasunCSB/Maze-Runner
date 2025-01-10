# Maze Runner

**Maze Runner** is a simple, CLI based maze game written in C++. Navigate through a series of mazes to reach the destination as quickly as possible to achieve the highest score.

---

## Requirements

To run the game, you will need the following:

1. **MinGW Compiler via MSYS2**  
   - Download the MSYS2 installer:  
     [msys2-x86_64-20241208.exe](https://www.msys2.org/)  
   - **Installation Guide**:  
     1. Download and run the installer linked above.  
        > Installing MSYS2 requires 64-bit Windows 10 or newer.  
     2. Enter your desired installation folder (short ASCII-only path on an NTFS volume, no accents, spaces, symlinks, subst, or network drives).  
     3. Follow the prompts to complete the installation.  
     4. After installation, a terminal for the UCRT64 environment will launch.  
     5. Install the MinGW GCC compiler by running the following command in the terminal:  
        ```bash
        pacman -S mingw-w64-ucrt-x86_64-gcc
        ```  
     6. Follow the on-screen prompts to complete the installation.  
     7. Verify the installation by running:  
        ```bash
        gcc --version
        ```  

   For additional details, see the [MSYS2 Installation Guide](https://www.msys2.org/).

2. **Alternatively**  
   Open the project in Dev-C++ and run it directly.

---

## How to Play

1. **Controls**:  
   - Use the following keys to navigate the maze:  
     - `W` - Move up  
     - `A` - Move left  
     - `S` - Move down  
     - `D` - Move right  

2. **Gameplay**:  
   - The game consists of **10 levels**, each with a timer.  
   - Your objective is to reach the destination in the maze before time runs out.  
   - The faster you complete each level, the higher your score.  

---

## Running the Game

1. **Using `game.bat`**:  
   - Double-click `game.bat` to compile and run the game directly.  
   - Ensure MSYS2 with MinGW GCC is installed and added to the PATH.  

2. **Using Dev-C++**:  
   - Open the project in Dev-C++.  
   - Compile and run the project from the IDE.  

---

## License

This project is open-source and available for use and modification. Contributions are welcome.
