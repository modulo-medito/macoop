cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S . -B ./build
cmake --build ./build --config Debug --target install -j 22 --
.\bin\macoop_demo.exe
pause
