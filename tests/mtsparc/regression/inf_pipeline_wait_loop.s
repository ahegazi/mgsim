/*
 This test case caused an infinite loop in the pipeline
 where the Waiting register was picked up from a later
 state in the pipeline, despite that the register in the
 register file was full.
*/
    .file "inf_pipeline_wait_loop.s"
    
    .globl main
    .align 64
main:
    clr %2
    allocates %2
    setlimit %2, 250
    set foo, %5
    crei %5, %2
    
    set X, %5
    ld  [%5], %1
    putg %1, %2, 0
    
    # Sync
    sync %2, %1
    release %2
    mov %1, %0
    end

    .align 64
    .registers 1 0 0 0 0 0
foo:
    print %tg0, 0
    end

    .data
X:
    .int 42
