	.name "jaw"
	.comment "corewar champion"


main:	       sti r1,%:live,%1
	and r1,%0,r2
	fork %:init_extra
	zjmp %:live

btorp2:	      sti r2,r3,r4
	zjmp %-37
btorp3:	     sti r2,r3,r4
	zjmp %-37
btorp:	     sti r2,r3,r4
	zjmp %-37
btorp4:	     sti r2,r3,r4
	zjmp %-37

live:	       live %42
	zjmp %:live

init_extra:	 fork %:extra2
extra:	      fork %:init_torp1
	fork %:init_torp3
	fork %:init_torp5
	fork %:init_torp7
	fork %:init_secu
	zjmp %:extra
extra2:	     fork %:init_btorp1
	fork %:init_btorp3
	fork %:init_btorp5
	fork %:init_btorp7
	zjmp %:extra2

	# back torpille
init_btorp1:	 fork %:init_btorp2
	ld %190054915,r2
	ld %-32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:btorp
init_btorp2:	 ld %67764187,r2
	ld %-32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:btorp
init_btorp3:	 fork %:init_btorp4
	ld %190054915,r2
	ld %-32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:btorp2
init_btorp4:	 ld %67764187,r2
	ld %-32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:btorp2
init_btorp5:	 fork %:init_btorp6
	ld %190054915,r2
	ld %-32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:btorp3
init_btorp6:	 ld %67764187,r2
	ld %-32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:btorp3
init_btorp7:	 fork %:init_btorp8
	ld %190054915,r2
	ld %-32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:btorp4
init_btorp8:	 ld %67764187,r2
	ld %-32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:btorp4

	# security
init_secu:	  ldi %:live,%0,r2
	ldi %:live,%2,r3
	xor r1,r1,r1
secu:	       sti r2,%:live,%0
	sti r3,%:live,%2
	zjmp %:secu

	# torpille
init_torp1:	 fork %:init_torp2
	ld %190054915,r2
	ld %32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:torp
init_torp2:	 ld %67698715,r2
	ld %32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:torp
init_torp3:	 fork %:init_torp4
	ld %190054915,r2
	ld %32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:torp2
init_torp4:	 ld %67698715,r2
	ld %32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:torp2
init_torp5:	 fork %:init_torp6
	ld %190054915,r2
	ld %32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:torp3
init_torp6:	 ld %67698715,r2
	ld %32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:torp3
init_torp7:	 fork %:init_torp8
	ld %190054915,r2
	ld %32,r3
	ld %0,r4
	xor r1,r1,r1
	zjmp %:torp4
init_torp8:	 ld %67698715,r2
	ld %32,r3
	ld %4,r4
	xor r1,r1,r1
	zjmp %:torp4
torp:	       sti r2,r3,r4
	zjmp %27
torp3:	      sti r2,r3,r4
	zjmp %27
torp2:	      sti r2,r3,r4
	zjmp %27
torp4:	      sti r2,r3,r4
	            zjmp %27
