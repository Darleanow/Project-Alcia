
# Project : Alcia

A text-based RPG game.

Made with love using VS2022.

**DISCLAIMER**: If you read the source code, take before anti-vomit pills, you'll probably need them :D

# Building Project Alcia

**Please note that back in time I wasn't sure about was I was doing, so it's only available on Windows, and too disgusting to be reworked**

Welcome, hero! 🌟 Ready to compile the epic saga of *Alcia* on your machine? Grab your coder's sword and follow the steps below to set up your development environment and start contributing to the realms of Alcia. Here's how to build the project using Visual Studio 2022—because even wizards need the right spells to conjure greatness!

## Prerequisites

Before we embark on this quest, you’ll need a few magical artifacts:

- **Visual Studio 2022** - Ensure you have the latest version installed and ready.
- **CMake** - For managing the dark arts of building complex projects.
- **Git** - To clone the repository and keep track of all the ancient scrolls.

## Cloning the Repository

First, open your favorite terminal, or use the integrated terminal in Visual Studio, and clone the repository:

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

And to build (Enjoy all the warnings):
Fun fact I had to roll back to C++14 as there was compilation issues using C++23 :D

```bash
cmake --build . --config Release
```

After building (now multiplatform):

```bash
.\bin\AlciaProject
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

## Author

- [@Darleanow](https://www.github.com/Darleanow)
