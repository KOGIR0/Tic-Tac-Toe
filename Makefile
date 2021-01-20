buildDir = build

TicTacToe.exe : main.o Button.o Field.o Sprite.o Text.o TicTacToe.o
		g++ build/main.o build/Button.o build/Field.o build/Sprite.o \
		build/Text.o build/TicTacToe.o -o build/TicTacToe.exe -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
		g++ -c main.cpp -o build/main.o

Button.o : Button.cpp Button.h
		g++ -c Button.cpp -o build/Button.o

Field.o : Field.cpp Field.h
		g++ -c Field.cpp -o build/Field.o

Sprite.o : Sprite.cpp Sprite.h
		g++ -c Sprite.cpp -o build/Sprite.o

Text.o : Text.cpp Text.h
		g++ -c Text.cpp -o build/Text.o

TicTacToe.o : TicTakToe.cpp TicTakToe.h
		g++ -c TicTakToe.cpp -o build/TicTacToe.o

clean :
		rm build/sfml_exe buld/main.o