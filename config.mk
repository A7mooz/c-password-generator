outdir = dist
REALSE_DIR = $(outdir)/release
DEBUG_DIR = $(outdir)/debug
outfile = main
SRC=$(shell find src -type f -name "*.c")

SHELL := /usr/bin/bash

HEADERS_DIR=includes/
FLAGS=-std=c23 -lssl -lcrypto -I $(HEADERS_DIR)
CFLAGS=$(FLAGS) -Wall -pedantic -Wextra -Werror
DEBUG_FLAGS=$(FLAGS) -Wall -pedantic -Wno-deprecated-declarations

# compiler and linker
CC = gcc
