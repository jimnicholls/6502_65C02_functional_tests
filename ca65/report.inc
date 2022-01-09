;**** report 6502 funtional test errors to standard I/O ****
;
;this include file is part of the 6502 functional tests
;it is used when you configure report = 1 in the tests
;
;to adopt the standard output vectors of your test environment
;you must modify the rchar and rget subroutines in this include
;
;I/O hardware may have to be initialized in report_init

.import report_error
.import report_init
.import report_success

;print message macro
.macro  rprt addr
        .local loop
        ldx #0
        lda addr
loop:
        jsr rchar
        inx
        lda addr,x
        bne loop
.endmacro
