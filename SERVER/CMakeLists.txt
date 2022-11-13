set(SERVER r-type_server)
project(${SERVER} LANGUAGES CXX)

set(SRC_SERVER  ./SOURCES/main.cpp
                ./SOURCES/ClientHandler.cpp
                ./SOURCES/Lobby.cpp
                ./SOURCES/UDPServer.cpp

                ./ENGINE/Engine.cpp
                ./ENGINE/Entity.cpp
                ./ENGINE/EntityManager.cpp
                
                ./ENGINE/components/ComponentsFactory.cpp
                ./ENGINE/components/ComponentsLibrary.cpp
                ./ENGINE/components/ComponentsManager.cpp
                
                ./ENGINE/components/cCollision/cCollision.cpp
                ./ENGINE/components/cControllable/cControllable.cpp
                ./ENGINE/components/cGraphical/cGraphical.cpp
                ./ENGINE/components/cSpeed/cSpeed.cpp
                ./ENGINE/components/cWeapon/cWeapon.cpp
                ./ENGINE/components/cBehaviour/cBehaviour.cpp
                ./ENGINE/components/cScene/cScene.cpp
                ./ENGINE/components/cText/cText.cpp

                ../TOOLS/SOURCES/Protocol.cpp
                ../TOOLS/SOURCES/SafeQueue.cpp
                ../TOOLS/SOURCES/CommunicationTools.cpp
	)

set(HEADER_SERVER   ./INCLUDE/ClientHandler.hpp
                    ./INCLUDE/Lobby.hpp
                    ./INCLUDE/UDPServer.hpp
                    ./INCLUDE/Engine.hpp
                    ./INCLUDE/Entity.hpp
                    ./INCLUDE/EntityManager.hpp
                    ./INCLUDE/ComponentsFactory.hpp
                    ./INCLUDE/ComponentsLibrary.hpp
                    ./INCLUDE/ComponentsManager.hpp
                    ./INCLUDE/iComponent.hpp
                    ./INCLUDE/cCollision.hpp
                    ./INCLUDE/cControllable.hpp
                    ./INCLUDE/cGraphical.hpp
                    ./INCLUDE/cSpeed.hpp
                    ./INCLUDE/cWeapon.hpp
                    ./INCLUDE/cBehaviour.hpp
                    ./INCLUDE/cScene.hpp
                    ./INCLUDE/cText.hpp

                    ../TOOLS/INCLUDE/CommunicationTools.hpp
                    ../TOOLS/INCLUDE/Protocol.hpp
                    ../TOOLS/INCLUDE/SafeQueue.hpp
	)

#	--------------- SERVER_LINKING ---------------
add_executable(${SERVER} ${HEADER_SERVER} ${SRC_SERVER})

target_link_libraries(${SERVER} CONAN_PKG::boost CONAN_PKG::sfml
    )