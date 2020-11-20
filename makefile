LIBRARIES = -lX11 -lglut -lGL -lGLU -lm
CFILES = main.cpp keyboard.cpp elements.cpp textures.cpp RgbImage.cpp
HEADERS = main.h keyboard.h elements.h  textures.h RgbImage.h
final: $(CFILES) $(HEADERS)
		g++ $(CFILES) -g -o final $(LIBRARIES)