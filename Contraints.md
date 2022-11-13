# CONTRAINTS

## RESTRICTIONS

### Build System, Dependencies, Cross Plateform

- [x] The project MUST use CMake as its buildsystem. No Makefiles are allowed
- [X] The project MUST be self-contained regarding the 3rd-party libraries that may be used.
- [x] The project MUST use a proper method for handling 3rd-party dependencies. (We are using conan)
- [x] The project MUST be Cross Platform. (Compiling on Linux AND Windows)
- [ ] Adequate VCS workflow is expected to be used for development. (No CI/CD)
- [ ] The project can be packaged/delivered/installed standalone, without requiring building from sources,
and with correct versioning.
- [x] You MUST provide a mean to build tarballs or installers for the game.


### Documentation

- [x] You MUST write the documentation in English.
- [x] You MUST have a README file.
- [x] The documentation have to be available and accessible in a modern way. (We have a doxygen documentation)


### Server

- [X] The server must be multi-threaded
- [X] The server MUST NOT block or wait for clients messages.
- [x] the game MUST run frame after frame on the server.
- [X] You MAY use Asio or Boost.Asio for networking. 


### Client

- [X] It MUST contain anything necessary to display the game and handle player input.
- [X] In any case the server MUST have authority on what happens in the end.
- [x] You may use the SFML.


### Protocol

- [X] You MUST design a binary protocol for client/server communications.
- [x] You MUST use UDP for communications between the server and the clients
- [x] ALL in-game communications MUST use UDP.
- [X] Such malformed messages or packets MUST NOT lead the client or server to crash.
- [x] You MUST document your protocol.


### Libraries

- [X] You must use the SFML on the client side and any rendering must be done using the SFML.
- [X] You MAY use Boost libraries on the server and/or the client. However, you have to justify each specific Boost
library usage.


### Game Engine

- [x] Implement a Game Engine
- [X] Entity-Component-System architectural pattern
- [x] Create an abstractions re-usable code

### General

- [x] The client MUST display a slow horizontal scrolling background representing space with stars, planets ...
This is the star-field.
- [ ] The star-field scrolling must NOT be tied to the CPU speed. Instead, you MUST use timers.
- [x] Players MUST be able to move using the arrow keys.
- [x] The server MUST be multithreaded.
- [ ] If a client crashes for any reason, the server MUST continue to work and MUST notify other clients in the
same game that a client crashed.
- [ ] The four players in a game MUST be distinctly identifiable (via color, sprite, etc.)
- [ ] There MUST be Bydos slaves in your game.
- [ ] Monsters MUST be able to spawn randomly on the right of the screen.
- [ ] The server MUST notify each client when a monster spawns, is destroyed, fires, kills a player, and so
on ... 

## Norme Commit

On this R-type project, we chose to have a pretty good commit history. For that, we tried to respect a certain pattern which first consist to put your initials between two brackets, then put a keyword choose between EDIT, ADD or REMOVE and finally the origin of the commit. Thanks to this pattern of commit, the history of our commits is clean and we can easily see what each commit did.

Exemple:  
[EB][EDIT] Edit Readme  
[MB][ADD] Add new file for the ECS  
[IB][DELETE] Delete useless files  


## Branches and Merge

During the entire duration of the project, each member of the team worked on differents branches. This was better for the organisation and less dangerous than work all together on the main branch. For the merge, in the beginning, we merged the different branches localy with a backup folder. This is not the right way to do this. This is why after the first month of the project, we tried and we used the pull requests in order to learn about how they work and and with the aim of merge our branch in a better way which is cleaner.