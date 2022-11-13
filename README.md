# R-Type

<a href="https://img.shields.io/badge/MADE%20WITH-C%2B%2B-ff69b4" alt="C++">
        <img src="https://img.shields.io/badge/MADE%20WITH-C%2B%2B-ff69b4" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" alt="SFML">
        <img src="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CONAN-blueviolet" alt="Conan">
        <img src="https://img.shields.io/badge/MADE%20WITH-CONAN-blueviolet" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" alt="Cmake">
        <img src="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" /></a>

![Menu](https://github.com/EpitechPromo2025/B-CPP-500-NAN-5-1-rtype-ismael.brossaud/blob/master/assets/screenshots/menu.png)

![Game](https://github.com/EpitechPromo2025/B-CPP-500-NAN-5-1-rtype-ismael.brossaud/blob/master/assets/screenshots/game.png)

This project aims to recreate the [R-Type](https://fr.wikipedia.org/wiki/R-Type) game with a multiplayer mode in order to play up to 4 players. For this, we had to implement a multi-threaded server using [Boost::asio](https://www.boost.org/doc/libs/1_75_0/doc/html/boost_asio.html) and [Boost::Thread](https://www.boost.org/doc/libs/1_64_0/doc/html/thread.html). For the graphical part, we used the [SFML](https://www.sfml-dev.org/).
Our project is divided into two parts: The Server and the Client both running at the same time.

## Prerequisites

Before launch the compilation, you will need to have on your computer :

Cmake 3.22.1  
make 4.3  
C++ Compiler 11.3.0  
Conan 1.52.0  

## Build System

**Linux:**

You can use the install.sh or use the following commands:

```
mkdir -p build; cd build; conan install .. --build=missing -s compiler.libcxx=libstdc++11 -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True; cmake ..; make

cd bin && cp -r r-type_client ../../ && cp -r r-type_server ../../

```

**Windows:**

You can use the install.bat or use the following commands:

```
mkdir build
cd build && conan install .. --build=missing  -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True && cmake .. && cmake --build . && cd bin && copy .\r-type_client.exe ..\..\ && copy .\r-type_server.exe ..\..\
```

## How to use the binaries

**In a Terminal**

```
./r-type_server
```

**In Another Terminal**

```
./r-type_client [NAME]
```

## How to use the Doxygen Documentation

We have a Doxygen Documentation. This is how to use it :

If you want to regenerate the doxygen do this :

- Paste ```apt-get install doxygen graphviz```
- Paste ```doxygen dconfig``` on your terminal

- Go on the ./docs/html/ directory.
- Copy the path of the index.html

Otherwise just do this:

- Go on the ./docs/html/ directory.
- Copy the path of the index.html
- Paste this path on internet and that's it !

## Constraints

* **Crosse-platform (Linux AND Windows)**
* **Graphical Library:**
  SFML Library
* **Build:**
  CMake
* **Package Manager:**
  Conan

If you want to know a little bit more about what were our contraints you can read our Contraints.md

## Game Engine

This is how our Project Architecture is:

![GameEngine](https://github.com/EpitechPromo2025/B-CPP-500-NAN-5-1-rtype-ismael.brossaud/blob/master/assets/screenshots/game_engine.png)

## Thank You for Reading

Do not hesitate to check the doxygen and to play to our game.
You can send us some feedback to our respective e-mail:

**firstname.surname@epitech.eu**

## Authors

* **Mathias Blanchard**
* **Ismael Brossaud**
* **Simon Tessier**
* **Enzo Bonato**
