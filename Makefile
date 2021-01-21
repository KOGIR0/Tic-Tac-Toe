buildDir = build
headerFiles = include/Button.h include/Field.h include/Sprite.h include/Text.h include/TicTakToe.h
sourceCPPFiles = src/Button.cpp src/Field.cpp src/Sprite.cpp src/Text.cpp src/TicTakToe.cpp

TicTacToe.exe : ${sourceCPPFiles} ${headerFiles}
		g++ main.cpp ${sourceCPPFiles} -o build/TicTacToe.exe -lsfml-graphics -lsfml-window -lsfml-system

clean :
		rm build/sfml_exe buld/main.o