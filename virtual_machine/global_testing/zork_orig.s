.name "zork"
.comment "I'M ALIIIIVE"

# l2:		sti r1, %:live, %1
# 		and r1, %0, r1
		
# live:	live %1
#  		zjmp %:live
l: live %-2
ld	%-12, r2
ldi	42, %1, r3

#add	r2, r3, r4
st r3, 10
#zjmp %-100
