HEADER_DIR   := include
SOURCE_DIR   := src
OBJECT_DIR   := obj
BEETROOT_DIR := ../beetroot

SOURCES      := $(shell find $(SOURCE_DIR) -name "*.cxx")
OBJECTS      := $(patsubst $(SOURCE_DIR)/%.cxx, $(OBJECT_DIR)/%.o, $(SOURCES))

CXX      := g++
CXXFLAGS := -O2 -Wall -Wextra -Wabi -Weffc++ -Wno-reorder
CXXFLAGS += -I$(HEADER_DIR)
CXXFLAGS += -I$(BEETROOT_DIR)
CXXFLAGS += $(shell root-config --cflags)

LIBS := 
LIBS += $(shell root-config --libs)
LIBS += -L$(BEETROOT_DIR)/.libs -lbeetroot

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cxx
	@mkdir -p $(OBJECT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

runExamples: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	
clean:
	rm -rf $(OBJECT_DIR)/*.o plots/* plotsC/* runExamples
