CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
BUILD_DIR = bin
INCLUDE_DIR = include

SRCS := $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET := $(BUILD_DIR)/main.exe

PYTHON := $(shell command -v python3 || command -v python)

VENV_DIR = env
PIP = $(VENV_DIR)/bin/pip
NOTEBOOK = stats/analysis.ipynb

MKDIR_P = mkdir -p

ifeq ($(OS),Windows_NT)
    RMDIR = rmdir /s /q $(BUILD_DIR)
    EXECUTABLE = $(TARGET)
    VENV_ACTIVATE = $(VENV_DIR)\Scripts\activate
    VENV_PYTHON = $(VENV_DIR)\Scripts\python.exe
else
    RMDIR = rm -rf $(BUILD_DIR)
    EXECUTABLE = ./$(TARGET)
    VENV_ACTIVATE = source $(VENV_DIR)/bin/activate
    VENV_PYTHON = $(VENV_DIR)/bin/python
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MKDIR_P) $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(VENV_DIR):
	$(PYTHON) -m venv $(VENV_DIR)
	$(VENV_PYTHON) -m pip install --upgrade pip
	$(VENV_PYTHON) -m pip install -r requirements.txt

clean:
	$(RMDIR)
	$(RMDIR) $(VENV_DIR)

run: all $(VENV_DIR)
	$(EXECUTABLE)
	$(VENV_PYTHON) -m notebook $(NOTEBOOK)

.PHONY: all clean run
