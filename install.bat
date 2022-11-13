mkdir build
cd build
pip3 install conan

conan install .. --build=missing  -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cmake ..
cmake --build .
cd bin
Move-Item -Path .\r-type_server.exe -Destination ..\..\bin\windows\
Move-Item -Path .\r-type_client.exe -Destination ..\..\bin\windows\