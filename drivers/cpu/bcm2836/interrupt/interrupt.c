#include <bcm2836/interrupt.h>
#include <bcm2836/clock/timer.h>
#include <memory/mem_rw.h>

__attribute__ ((naked, aligned(32))) static void interrupt_vectors(void)
{
	asm volatile( "b bad_exception\n"
				  "b bad_exception\n"
				  "b interrupt_swi\n"
				  "b interrupt_prefetch_abort\n"
				  "b interrupt_data_abort\n"
				  "b bad_exception\n"
				  "b interrupt_irq\n"
				  "b bad_exception\n");
}

__attribute__ ((naked)) void bad_exception(void)
{
	while(1);
}


__attribute__ ((interrupt ("SWI"))) void interrupt_swi(void)
{
	while(1);
}


__attribute__ ((interrupt ("IRQ"))) void interrupt_irq(void)
{
	while(1);
}


__attribute__ ((interrupt ("ABORT"))) void interrupt_prefetch_abort(void)
{
	while(1);
}


__attribute__ ((interrupt ("ABORT"))) void interrupt_data_abort(void)
{
	while(1);
}



void init_interrupts(void)
{
	
	asm volatile("mcr p15, 0, %[addr], c12, c0, 0" : : [addr] "r" (&interrupt_vectors));
	//asm volatile("cpsie i");
	
	write32(INTERRUPT_ENABLE_IRQ_BASIC, 1);
	
	init_timer();
	
}
