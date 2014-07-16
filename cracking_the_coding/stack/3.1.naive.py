S = 300 

lst = [None] * S 

class Stack:
        def __init__(self, name=None, base=None,size=None):
                self.name = name
                self.base = base
                self.size = size
                self.top = -1
		self.cur_min = None

        def push(self, value):
		global lst
                if self._overflowed():
                        return "{} is overflowed".format(self.name)
		self.top = self.top + 1 
		if self.cur_min == None:
			d = (value, value)
			self.cur_min = value
		elif self.cur_min <  value:
			d = (value,self.cur_min)
			#self.cur_min does not change
		else:
			d = (value,value)
			self.cur_min = value

                lst[self.base + self.top] = d
		#print lst
                return "Success. {} inserted into {}".format(value,self.name)
    
        def pop(self):
		global lst
                if self._underflowed():
                        return "{} is underflowed. Nothing poped".format(self.name)
		index = self.base + self.top
                x = lst[self.base + self.top]
                self.top = self.top - 1 # decrement top first, but return top + 1 next line
                return "success, {} poped from {}".format(x, self.name)
                pass

        def _overflowed(self):
                if self.top >= self.size-1:
                        return True
                return False
                pass
    
        def _underflowed(self):
                if self.top < 0 : 
                        return True
                return False

                pass


class ThreeStack:
        def __init__(self):
                self.stacks = []
                self.stacks.append( Stack(name = "s1", base = 0, size = S/3) )
                self.stacks.append( Stack(name = "s2", base = S/3, size = S/3) )
                self.stacks.append( Stack(name = "s3", base = S/3 * 2, size = S/3) )

        def push(self, stack = 0, value = None):
                if stack <3 and stack > -1:
                        s = self.stacks[stack]
                        return s.push(value)
                return "wrong stack"
        def pop(self, stack=0):
                if stack <3 and stack > -1:
                        s = self.stacks[stack]
                        return  s.pop()
                return "wrong stack"

def test():
	#print S
        ts = ThreeStack()
	print ts.push(stack = 0, value = 10)
        print ts.push(stack = 0, value = 5)
        print ts.push(stack = 0, value = 2)
	print ts.push(stack = 0, value = 20)
	print ts.push(stack = 0, value = 1)

        print ts.pop(stack = 0)
        print ts.pop(stack = 0)
        print ts.pop(stack = 0)
        print ts.pop(stack = 0)
        print ts.pop(stack = 0)

        #print ts.pop(stack = 1)

        pass
if __name__ == "__main__":
        test()
