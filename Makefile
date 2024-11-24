include config.mk

./$(REALSE_DIR)/${ouutfile}: ./$(SRC) ./$(REALSE_DIR)
	${CC} -o $(REALSE_DIR)/$(outfile) ${CFLAGS} -s ${SRC}

debug: ./$(DEBUG_DIR)
	${CC} -o $(DEBUG_DIR)/$(outfile) ${DEBUG_FLAGS} -g ${SRC}

./$(REALSE_DIR):
	mkdir -p $(REALSE_DIR)

./$(DEBUG_DIR):
	mkdir -p $(DEBUG_DIR)

clean:
	rm -rf ${outdir}/*
