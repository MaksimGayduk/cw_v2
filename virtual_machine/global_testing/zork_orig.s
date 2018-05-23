.name "zork"
.comment "I'M ALIIIIVE"

# l2:		sti r1, %:live, %1
# 		and r1, %0, r1
		
# live:	live %1
#  		zjmp %:live
live %-2
ld	518, r2
st r2, 10
