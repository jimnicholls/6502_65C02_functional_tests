TARGETS =	6502_functional_test.prg

.PHONY: all clean
.SECONDARY:
.SUFFIXES:

all: $(TARGETS)


#-------------------------------------------------------------------------------

C1541 = c1541

6502_tests.d81: $(TARGETS)
	-rm -f $@
	$(C1541) -format '6502 tests,6t' d81 $@
	$(C1541) $@ \
		-write 6502_functional_test.prg "6502"


#-------------------------------------------------------------------------------

AS = ca65
ASFLAGS = --target none --cpu 4510 -W1
LD = ld65
LDFLAGS = --config mega65.cfg

%.prg: %.o crt0.o report.o
	$(LD) $(LDFLAGS) -Ln $*.lbl --mapfile $*.map -o $@ $+

%.o: %.ca65
	$(AS) $(ASFLAGS) --listing $*.lst --list-bytes 7 -o $@ $^


#-------------------------------------------------------------------------------

clean:
	-rm -f *.lib *.lbl *.lst *.map *.o *.prg
