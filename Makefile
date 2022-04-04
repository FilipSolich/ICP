#
# Makefile
#
# Date:   4. 3. 2022
# Author: Filip Solich <xsolic00@stud.fit.vutbr.cz>
#

TARGET = icp

DOC_DIR      = doc
EXAMPLES_DIR = examples
SRC_DIR      = src

PACK       = 1-xsolic00-xsechr00.tar.gz
PACK_FILES = $(EXAMPLES_DIR) $(SRC_DIR) Doxyfile Makefile README.txt

.PHONY: all run example clean doxygen pack

all:
	qmake $(SRC_DIR)/$(TARGET).pro -o $(SRC_DIR)/
	make -C $(SRC_DIR)
	mv $(SRC_DIR)/$(TARGET) .

run: $(TARGET)
	./$(TARGET)

example: $(TARGET)
	./$(TARGET) $(EXAMPLES_DIR)/export.json

clean:
	make clean -C $(SRC_DIR)
	$(RM) $(SRC_DIR)/Makefile
	$(RM) $(SRC_DIR)/.qmake.stash
	$(RM) -r $(TARGET) $(PACK) $(DOC_DIR)/html

doxygen:
	doxygen

pack: $(PACK_FILES)
	tar -czvf $(PACK) $(PACK_FILES)
