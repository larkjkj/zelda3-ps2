BIN		:= zelda3.elf
SRCS		:= $(wildcard src/*.c snes/*.c)  third_party/gl_core/gl_core_3_1.c third_party/opus-1.3.1-stripped/opus_decoder_amalgam.c
OBJS		:= $(patsubst %.c,%.o,$(SRCS))
ZELDA_ASSETS	:= zelda3_assets.dat

INCS		:= -I.

EE_INCS		:= -I$(PS2SDK)/ee/include -I$(PS2SDK)/common/include \
		-I$(PS2SDK)/ports/include -I$(PS2SDK)/ports/include \
		-I$(GSKIT)/include -I$(PS2SDK)/ports/include/SDL2

EE_LDFLAGS	:= -L$(GSKIT)/lib -L$(PS2SDK)/ee/lib -L$(PS2SDK)/ports/lib \
		-lSDL2 -lSDL2main -ldebug -lkernel -lps2_drivers \
		-lgskit -ldmakit -lopus -lpatches -lpad

#CFLAGS		:= -DDEBUG=1 -DPADEMU=1


.default: $(BIN) zelda3_assets.dat

venv: 
	python -m venv venv
	venv/bin/pip install -r requirements.txt
	venv/bin/python assets/restool.py --extract-from-rom

%.o: %.c
	mips64r5900el-ps2-elf-gcc -D_EE -G0 -O2 $(CFLAGS) $(INCS) $(EE_INCS) -c $^ -o $@ $(EE_LDFLAGS)

$(BIN): $(OBJS)
	mips64r5900el-ps2-elf-gcc $(INCS) $(EE_INCS) -T$(PS2SDK)/ee/startup/linkfile $^ -o $@ $(EE_LDFLAGS)

clean: $(OBJS)
	rm -rf $(OBJS) $(BIN)
