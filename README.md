# Dungeon Descent

A Windows dungeon game developed as the University of KwaZulu-Natal **COMP315 Group 7** team project.

Players choose a character class and progress through dungeon rooms containing battles, encounters, shops, chests, libraries, and rest areas. The project combines C++ gameplay classes with a Windows Forms interface and SFML graphics/audio.

## Technology

| Component | Technology |
| --- | --- |
| Gameplay | C++ classes and inheritance |
| Windows interface | C++/CLI and Windows Forms |
| Graphics and audio | SFML 3.0.0 |
| Build toolchain | Visual Studio 2022 / MSVC v143; x64 configurations use C++20 |
| Runtime target | .NET Framework 4.7.2 |

## Story

Choose one of four heroes and explore a magical dungeon to rescue a princess believed to be held by the sorcerer Malvel. Riddles, battles and story choices shape character statistics and lead to three possible endings.

## Features

- Warrior, Ranger, Mage, and Rogue character classes with different statistics and abilities.
- Dungeon progression across rooms, floors, and biomes.
- Battles, story encounters, riddles, and character progression.
- Shops, treasure chests, libraries, and rest areas.
- Animated introduction, music, and graphical game screens.

## Code map

| Files or directory | Responsibility |
| --- | --- |
| `StartScreen.cpp`, `StartScreen.h` | Entry point, animated introduction, and menu |
| `GameScreen.h` | Main game interface and event handling |
| `Character.*`, `Warrior.*`, `Ranger.*`, `Mage.*`, `Rogue.*` | Shared character model and specialised classes |
| `RoomBase.*` | Shared dungeon room behaviour |
| `Battle.*`, `Monster.*` | Battle and monster systems |
| `Encounter.*`, `Riddles.*`, `Lore.*` | Encounters, riddles, and narrative |
| `Shop.*`, `Chest.*`, `Library.*`, `Respite.*` | Interactive room types |
| `Music.*` | Audio support |
| `images/`, `fonts/`, `music/`, `candle/`, `textfiles/` | Runtime assets |
| `Dungeon_Descent.sln`, `Dungeon_Descent.vcxproj` | Visual Studio solution and build settings |

## Build requirements

- Windows.
- Visual Studio 2022 with **Desktop development with C++**, the **MSVC v143 toolset**, and **C++/CLI support**.
- The **.NET Framework 4.7.2 targeting pack** and Windows SDK.
- SFML **3.0.0** development libraries built for a compatible MSVC toolchain and x64 architecture.

## Build and run

1. Clone the repository:

   ```bash
   git clone https://github.com/DarianRobert/Dungeon-Descent.git
   cd Dungeon-Descent
   ```

2. Open `Dungeon_Descent.sln` in Visual Studio and select **Release | x64**.
3. In the project properties for that configuration, replace the developer-specific SFML include and library paths. The repository includes `SFML-3.0.0/`; use its `include` and `lib` directories if compatible with your toolchain, or use your own SFML 3.0.0 installation:
   - **C/C++ > General > Additional Include Directories:** the SFML `include` directory.
   - **Linker > General > Additional Library Directories:** the SFML `lib` directory.
   - Keep the SFML graphics, window, system, and audio libraries in **Linker > Input > Additional Dependencies**.
4. Put the matching SFML runtime DLLs beside the built executable.
5. Set **Debugging > Working Directory** to `$(ProjectDir)` so the relative asset paths resolve, then build and start the application through Visual Studio.

For a Debug build, configure the Debug | x64 settings separately and use the matching debug libraries and DLLs. To run outside Visual Studio, keep the executable, matching runtime DLLs, and asset directories together and launch from that directory.

## Current limitations

- The checked-in project contains developer-specific SFML paths that need adjustment on another machine.
- The application depends on Windows Forms and C++/CLI; a Linux or macOS build is not currently provided.
- Tracked build outputs and a bundled SFML distribution make the repository larger than a source-only checkout. The supplied `x64/Release/` files are historical build artefacts, not a verified fresh release.
- A clean Windows build and a packaged release have not yet been verified on a fresh development environment.

## Authors

Lokadi Naicker  
Arjun Ramphal  
Darian Robert  
Ashutosh Maraj  
Zaid Kajee  
Sikhulile Dlamini  
Keolin Naicker  
Zaheera Ganie  
Nafees Abdulla

This portfolio fork preserves the [original team repository](https://github.com/ArjunRamphal/Dungeon_Descent) and its commit history.

[My project portfolio](https://darianrobert.github.io/)

