TARGETS =	6502_functional_test.bin \
			65C02_extended_opcodes_test.bin

.PHONY: all clean
.SECONDARY:
.SUFFIXES:

all: $(TARGETS)


#-------------------------------------------------------------------------------

AS = ca65
ASFLAGS = --target none --cpu 4510 -W1
LD = ld65
LDFLAGS = --config hyppotest.cfg

%.bin: %.o crt0.o report.o
	$(LD) $(LDFLAGS) -Ln $*.lbl --mapfile $*.map -o $@ $+

%.o: %.ca65
	$(AS) $(ASFLAGS) --listing $*.lst --list-bytes 7 -o $@ $^


#-------------------------------------------------------------------------------

clean:
	-rm -f *.lib *.lbl *.lst *.map *.o *.bin
