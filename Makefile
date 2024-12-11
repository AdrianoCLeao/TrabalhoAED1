CC = gcc
CFLAGS = -Wall -Iinclude
SRC_DIR = src
BUILD_DIR = bin
INCLUDE_DIR = include

SRCS := $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET := $(BUILD_DIR)/main.exe

ifeq ($(OS),Windows_NT)
    PYTHON := python
    MKDIR_P = if not exist "$(subst /,\,$(strip $(1)))" mkdir "$(subst /,\,$(strip $(1)))"
    RMDIR = rmdir /s /q
    EXECUTABLE = $(TARGET)
else
    PYTHON := $(shell command -v python3 || command -v python)
    MKDIR_P = mkdir -p $(1)
    RMDIR = rm -rf
    EXECUTABLE = ./$(TARGET)
endif

VENV_DIR = env
PIP = $(VENV_PYTHON) -m pip
NOTEBOOK = stats/analysis.ipynb

all: $(TARGET) $(VENV_DIR)

$(TARGET): $(OBJS)
	$(call MKDIR_P, $(BUILD_DIR))
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(call MKDIR_P, $(dir $@))
	$(CC) $(CFLAGS) -c $< -o $@

$(VENV_DIR):
	$(PYTHON) -m venv $(VENV_DIR)
	$(VENV_ACTIVATE)
	$(PIP) install --upgrade pip
	$(PIP) install -r requirements.txt

install-deps: $(VENV_DIR)
	$(PIP) install -r requirements.txt

clean:
	$(RMDIR) $(BUILD_DIR)
	$(RMDIR) $(VENV_DIR)

run: $(TARGET)
	$(EXECUTABLE)
	$(VENV_PYTHON) -m notebook $(NOTEBOOK)

run-c: $(TARGET)
	$(EXECUTABLE)

.PHONY: all clean run install-deps run-c
