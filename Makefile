CC=g++
CFLAGS=-Wall -Werror
STD= -std=c++20 # Added STD flag because compiling wasn't working on macbook
TARGET=main.exe
SRC=main.cpp 
OBJ=$(SRC:.cpp=.o) # OBJ=$(SRC: .c= o), wrong: cpp instead of c and .o, fix the spacing too because make is anal with its formatting
HEADERS=color.h vec3.h ray.h rtweekend.h sphere.h hittable.h hittable_list.h interval.h camera.h material.h

# 'all' target
all: $(TARGET)

# Link the target with the object files
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile the source files into object files
$(OBJ): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(STD) -c $(SRC)


# run the target file
run:$(TARGET)
	$(TARGET) > image.ppm

# 'clean' target for cleaning up
clean:
	rm -f $(TARGET) $(OBJ)


	