#===- common.mak --------------------------------------------------------===#  
#
#                       The Libc-Bench Project
#
#  This file is distributed under the GPLv2 License.
#  See LICENSE for details.
#
#===---------------------------------------------------------------------===# 

include common.mak

#===---------------------------------------------------------------------===# 
# Set Up PORT_DIR
#===---------------------------------------------------------------------===# 
ifndef PORT_DIR
  ARCH=$(shell if [[ `uname 2> /dev/null` ]] ; then uname -m | tr A-Z a-z; fi)
  OS=$(shell uname -s | tr A-Z a-z)
  PORT_DIR=$(ARCH)-$(OS)
endif # PORT_DIR

ifndef PORT_DIR
$(error PLEASE define PORT_DIR! (e.g. make PORT_DIR=simple))
endif

#===---------------------------------------------------------------------===# 
# include portme.mak
#===---------------------------------------------------------------------===# 
vpath %.c $(PORT_DIR)
vpath %.h $(PORT_DIR)
vpath %.mak $(PORT_DIR)
include $(PORT_DIR)/portme.mak

#===---------------------------------------------------------------------===# 
# Set Up individual files
#===---------------------------------------------------------------------===# 
SRC_DIR = ./src
OBJ_DIR = ./objs
CORE_FILES = malloc pthread regex stdio string utf8
SOURCES = $(addprefix $(SRC_DIR)/, $(addsuffix .c,$(CORE_FILES)))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o,$(CORE_FILES)))

PAT_DIR = ./pat
PAT_FILES = Color Test PrettyResultPrinter pat ManagedStatic Timer
PAT_SOURCES = $(addprefix $(PAT_DIR)/lib/, $(addsuffix .cpp,$(PAT_FILES)))
PAT_OBJECTS = $(addprefix $(OBJ_DIR)/pat/, $(addsuffix .o,$(PAT_FILES)))
PAT_INCLUDES = -I$(PAT_DIR)/include -I$(PORT_DIR)

#===---------------------------------------------------------------------===# 
# compile
#===---------------------------------------------------------------------===# 
.PHONY: all libpat create_folders

all: create_folders $(OBJECTS) libpat
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.cpp $(PAT_INCLUDES)
	$(CXX) $(LDFLAGS) $(XLDFLAGS) -o libc-bench $(OBJECTS) $(OBJ_DIR)/main.o -L$(OBJ_DIR) -lpat -lpthread

create_folders:
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(OBJ_DIR)/$(PAT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(XCFLAGS) -c $< -o $@ 

libpat: $(PAT_OBJECTS)
	$(AR) $(OBJ_DIR)/libpat.a $(PAT_OBJECTS)

$(OBJ_DIR)/pat/%.o: $(PAT_DIR)/lib/%.cpp
	$(CXX) $(PAT_INCLUDES) $(CXXFLAGS) $(XCXXFLAGS) -c $< -o $@ 

#===---------------------------------------------------------------------===# 
# Cleaning
#===---------------------------------------------------------------------===# 
clean:
	$(RM) $(OBJ_DIR) libc-bench
