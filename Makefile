CC = gcc
CFLAGS = -Wall -Iinclude

SRC_DIR = src
BUILD_DIR = bin
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(BUILD_DIR)/main.exe

ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
    RMDIR = rmdir /s /q $(BUILD_DIR)
    EXECUTABLE = $(TARGET)
else
    MKDIR = mkdir -p $(BUILD_DIR)
    RMDIR = rm -rf $(BUILD_DIR)
    EXECUTABLE = ./$(TARGET)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MKDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMDIR)

run: all
	$(EXECUTABLE)

.PHONY: all clean run
