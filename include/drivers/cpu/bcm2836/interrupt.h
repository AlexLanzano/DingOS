#ifndef INTERRUPT_H
#define INTERRUPT_H

#define INTERRUPT_BASE 0x3f00b000
#define INTERRUPT_IRQ_BASIC_PENDING INTERRUPT_BASE + 0x200
#define INTERRUPT_IRQ1_PENDING INTERRUPT_BASE + 0x204
#define INTERRUPT_IRQ2_PENDING INTERRUPT_BASE + 0x208
#define INTERRUPT_FIQ_CONTROL INTERRUPT_BASE + 0x20C
#define INTERRUPT_ENABLE_IRQ1 INTERRUPT_BASE + 0x210
#define INTERRUPT_ENABLE_IRQ2 INTERRUPT_BASE + 0x214
#define INTERRUPT_ENABLE_IRQ_BASIC INTERRUPT_BASE + 0x218
#define INTERRUPT_DISABLE_IRQ1 INTERRUPT_BASE + 0x21C
#define INTERRUPT_DISABLE_IRQ2 INTERRUPT_BASE + 0x220
#define INTERRUPT_DISABLE_IRQ_BASIC INTERRUPT_BASE + 0x224

#define BASIC_ARM_TIMER_IRQ         (1 << 0)
#define BASIC_ARM_MAILBOX_IRQ       (1 << 1)
#define BASIC_ARM_DOORBELL_0_IRQ    (1 << 2)
#define BASIC_ARM_DOORBELL_1_IRQ    (1 << 3)
#define BASIC_GPU_0_HALTED_IRQ      (1 << 4)
#define BASIC_GPU_1_HALTED_IRQ      (1 << 5)
#define BASIC_ACCESS_ERROR_1_IRQ    (1 << 6)
#define BASIC_ACCESS_ERROR_0_IRQ    (1 << 7)

void enable_interrupts();
void init_interrupts();
#endif
