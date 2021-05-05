rmdir out\build
cmake -G "MinGW Makefiles" -DGLFW_BUILD_DOCS=OFF -S . -B out/build
cmake -G "MinGW Makefiles" -DGLFW_BUILD_DOCS=OFF -S . -B out/build
cd out\build
mingw32-make
opengl_2dscene.exe
cd ..\..
