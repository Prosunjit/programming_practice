import sys
'''replace x by y in str'''

def substring_replace( str, x, y):
	if len(x) > len(str):
		return 0
	str_l = len(str)
	x_l = len(x)
	y_l = len(y)
	index = 0
	match_index = 0
	start_index = 0
	end_index = 0
	count = 0
	new_str = ""
	t = ""
	while (index < str_l) :
		if str[index] == x[match_index]:
			t += str[index]
			index += 1
			match_index += 1
			if (match_index == 1) :
				start_index = index
			elif match_index == x_l:
				end_index == index
				count += 1
				new_str += y
				t=""
				#replace routing...

				match_index = 0
			else:
				pass
		else:
			new_str += t
			t = ""
			new_str += str[index]
			match_index = 0
			index +=1

	return (new_str, count)

def test():
	print substring_replace(sys.argv[1], sys.argv[2], sys.argv[3])
test()
	
