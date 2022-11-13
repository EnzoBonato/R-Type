set(CLIENT r-type_client)
project(${CLIENT} LANGUAGES CXX)

set(SRC_CLIENT  ./SOURCES/main.cpp
                ./SOURCES/UDPClient.cpp
                
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
                ./ENGINE/components/cShape/cBarLife.cpp

                ../TOOLS/SOURCES/Protocol.cpp
                ../TOOLS/SOURCES/CommunicationTools.cpp
                ../TOOLS/SOURCES/SafeQueue.cpp
	)

set(HEADER_CLIENT   ./INCLUDE/UDPClient.hpp
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
                    ./INCLUDE/cBarLife.hpp

                    ../TOOLS/INCLUDE/SafeQueue.hpp
                    ../TOOLS/INCLUDE/CommunicationTools.hpp
                    ../TOOLS/INCLUDE/Protocol.hpp
                    ../TOOLS/INCLUDE/DataBuffer.hpp
	)

#	--------------- CLIENT_LINKING ---------------
add_executable(${CLIENT} ${HEADER_CLIENT} ${SRC_CLIENT})

target_link_libraries(${CLIENT} CONAN_PKG::boost CONAN_PKG::sfml
    )