LIBRARIES = -lX11 -lglut -lGL -lGLU -lm
CFILES = main.cpp keyboard.cpp elements.cpp
HEADERS = main.h keyboard.h elements.h 
final: $(CFILES) $(HEADERS)
		g++ $(CFILES) -o final $(LIBRARIES)