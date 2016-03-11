CC 			:= g++
FLAGS 		:= -std=c++14

MKDIR_P 	:= mkdir -p
RM_DIR 		:= $(RM) -r

OUT_DIR 	:= bin
TARGET 		:= huffman
SRC_DIR		:= src
SRC	 		:= main.cpp HuffmanCode.cpp Code.cpp Symbol.cpp StringUtils.cpp

#--------------------------DON'T TOUCH BELOW THIS-------------------------------
OBJS 		:= $(SRC:.cpp=.o)
OBJS 		:= $(addprefix $(OUT_DIR)/, $(OBJS))

.PHONY: directories clean

default: all

all: directories $(OUT_DIR)/$(TARGET)

directories:
	@$(MKDIR_P) $(OUT_DIR)

$(OUT_DIR)/$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(OUT_DIR)/$(TARGET) $(OBJS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	$(RM_DIR) $(OUT_DIR)