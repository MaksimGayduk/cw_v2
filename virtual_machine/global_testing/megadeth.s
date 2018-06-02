.name "Megadeth"
.comment "Dread and the Fugitive Mind"


castle:
	st r1, 6
	live %-42
	zjmp %-5
	ld %1, r2

	# Код для записи интсрукции жизни 
	ld %880, r3
	ld %33682435, r4	 # 02 01 f4 03
	ld %1879114227, r5

	ld %1879245298, r6

	st r2, 500			# write live instr
	st r1, 499			# player code
	st r3, 498			# 03 70
	st r4, 497			# 02 01 f4 03
	st r5, 496			# 70 01 01 F3
	
	st r3, 495
	st r6, 493

	# st r3, 493
	# st r6, 492
	# st r7, 491

	and r16, 0, r16
	fork %457
	zjmp %:castle


# live:
# 	live %-42
# 	zjmp %:live
	
# attacker:
# 	fork %1
# 	and r3, 0, r3
# 	zjmp %:live
