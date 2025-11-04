.section .startup, "ax"

    .org .startup + 0x0040

__system_reset:
    b __system_reset_handler

    .org .startup + 0x0200

__system_reset_handler:
    # end of SPPE-SRAM is 0xFFFF_FFFF
    # initiallize stack pointer to 0xFFFF_FFF8

    lis %r1, 0xFFFF         # r1 = 0xFFFF0000
    ori %r1, %r1, 0xFFF8    # r1 = 0xFFFF_FFF8
