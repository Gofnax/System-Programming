TARGET := prog

SRC_DIR := ./src
INCLUDE_DIR := ./include
BUILD_DIR = ./build
BIN_DIR = ./bin
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
CC := gcc
CFLAGS := -g -std=c99 -Wall -Wextra -Werror
CPPFLAGS := -I$(INCLUDE_DIR) -MMD -MP
LDLIBS := -lm

.PHONY: all
all: directories make_target

.PHONY: directories
directories:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

.PHONY: make_target
make_target: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

-include $(DEPS)

# Copyrights resereved for the great Dani Rusa