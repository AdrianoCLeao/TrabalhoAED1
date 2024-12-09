CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
BUILD_DIR = bin
INCLUDE_DIR = include

SRCS := $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET := $(BUILD_DIR)/main.exe

MKDIR_P = mkdir -p

ifeq ($(OS),Windows_NT)
    RMDIR = rmdir /s /q $(BUILD_DIR)
    EXECUTABLE = $(TARGET)
else
    RMDIR = rm -rf $(BUILD_DIR)
    EXECUTABLE = ./$(TARGET)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MKDIR_P) $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMDIR)

run: all
	$(EXECUTABLE)

.PHONY: all clean run
