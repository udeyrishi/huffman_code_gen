# Copyright 2016 Udey Rishi
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CC          := g++
FLAGS       := -std=c++14

MKDIR_P     := mkdir -p
RM_DIR      := $(RM) -r

OUT_DIR     := bin
TARGET      := huffman
SRC_DIR     := src
SRC         := main.cpp HuffmanCode.cpp Code.cpp Symbol.cpp StringUtils.cpp DoubleUtils.cpp

#--------------------------DON'T TOUCH BELOW THIS-------------------------------
OBJS        := $(SRC:.cpp=.o)
OBJS        := $(addprefix $(OUT_DIR)/, $(OBJS))
TARGET      := $(OUT_DIR)/$(TARGET)

.PHONY: directories clean

default: all

all: directories $(TARGET)

directories:
	@$(MKDIR_P) $(OUT_DIR)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	$(RM_DIR) $(OUT_DIR)

rebuild: clean all
