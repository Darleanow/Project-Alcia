
# Project : Alcia

A text-based RPG game.

Made with love using neovim.

# Building Project Alcia

Welcome, hero! 🌟 Ready to compile the epic saga of *Alcia* on your machine? 
Grab your coder's sword and follow the steps below to set up your development environment and start contributing to the realms of Alcia.
Here's how to build the project using CMake.

## Prerequisites

- A C++23 compatible Compiler
- CMake
- Git

## Cloning the Repository

```bash
git clone https://github.com/Darleanow/Project-Alcia.git
cd Project-Alcia
```

This spell summons the latest version of the project into your local machine.

## Configuring with CMake

Navigate to the root directory of the project where you find the `CMakeLists.txt`. Let's conjure a build directory for all the build artifacts:

```bash
mkdir build && cd build
```

Now, invoke CMake to prepare the building grounds:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

Now, compile project:

```bash
cmake --build . --config Release
```

After building (now multiplatform):

```bash
./Alcia
```

## Loots list

| Rarity    | Name           | Obtainable from            |Amount | Rate    | Price   |
| :-------- | :------------- | :------------------------- |:----- |:------- |:------- |
| `common`  | `Zombie Flesh` | Zombies                    | 0 - 3 | 100 %   | 2/u |
| `rare`    | `Zombie Eye`   | Zombies                    | 0 - 2 | 40 %    | 10/u|
| `common`    | `Bone Shard` | Skelettons                 | 0 - 5 | 100 %   | 4/u |
| `rare`    | `Bones`        | Skelettons                 | 0 - 5 | 30 %    | 15/u|
| `rare`    | `Troll Finger` | Troll                      | 0 - 3 | 100 %   | 25/u|
| `rare`    | `Empty Sack`   | Troll                      | 0 - 1 | 30 %    | 20/u|
| `rare`    | `Troll Finger` | Super Troll                | 0 - 5 | 100 %   | 25/u|
| `epic`    | `Old Belt`     | Super Troll                | 0 - 1 | 30 %    | 60/u|
| `rare`    | `Kobold tail`  | Kobold                     | 0 - 1 | 100 %   | 30/u|
| `epic`    |`Kobold Scepter`| Kobold                     | 0 - 1 | 10 %    | 64/u|
| `common`  |`Oreade Powder `| Oreade                     | 2 - 7 | 100 %   | 10/u|
| `epic`    |`Magic Fragment`| Oreade                     | 0 - 1 | 10 %    | 85/u|
| `epic`    | `Dragon Scale `| Baby Dragon                | 0 - 5 | 20 %    | 75/u|
| `legendary`|`Dragon Tooth `| Baby Dragon                | 0 - 2 | 10 %    |122/u|
| `epic`    | `Dragon Scale `| Mama Dragon                | 0 - 15 | 30 %   | 75/u|
| `legendary`|`Dragon Tooth `| Mama Dragon                | 0 - 4 | 20 %    |122/u|

