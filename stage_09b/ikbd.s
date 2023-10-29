; Author: 

	xdef	_ikbd_isr
	xref	_ikbd_irq

_ikbd_isr:
	movem.l	d0/a0,-(sp)
	jsr	_ikbd_irq
	movem.l	(sp)+,d0/a0
	rte
