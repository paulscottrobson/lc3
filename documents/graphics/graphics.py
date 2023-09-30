#
#			There are 128 graphics characters, stored from 8000-83FF. 
#
#			Colour of a character is set by the upper 3 bits and the border
#
#			Bit 3 selects the alternate colour scheme for everything
# 			Bit 4 forces the background to black for display only.
# 			Bit 5 enables bit 5 of the graphics character when calculating colour
# 			Bit 6 enables bit 6 of the graphics character when checking colour

def reverse(n):
	n = (n << 1) | (n >> 3)
	return n & 7
	return (4 if (n & 1) != 0 else 0) + (n & 2) + (1 if (n & 4) != 0 else 0)

def getColour(charID,border):
	charID = charID & (border | 0x80)							# clear bits 5 and 6 of char ID if bits 5 and 6 not set in border, ignoring them.
																# throw away bits 0..4 which have no effect on colour.

	if charID == 0 and (border & 0x10) != 0:					# force background to black if bit 4 set.
		return 0

	colour =  (charID >> 5) 									# xor the border colour and the upper 3 bits
	colour ^= (border & 7)

	return colour

colours = ["black","blue","red","magenta","green","cyan","yellow","white"]

for scheme in range(0,8):
	print("Colour scheme {0:2} border colour {1:7} set {2}".format(scheme,colours[scheme & 7],scheme >> 3))
	cset = []
	for cbits in range(0,8):
		c = getColour(cbits << 5,scheme | 0x40)
		#c = colours[c]
		if c not in cset:
			cset.append(c)
	print("\t",cset)


