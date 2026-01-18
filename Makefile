TARGET = atari_ps1
TYPE = ps-exe

SRCS = main.c 

# Se usi PSn00bSDK o simili, questi path sono standard
CPPFLAGS += -Iinclude
LDFLAGS += -Llib
LIBS += -lpsxspx -lpsxgpu -lpsxgte -lpsxetc -lpsxapi -lc

include ../common.mk # Adattare in base alla root del toolchain nella Action
