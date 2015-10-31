#!/usr/bin/env python

"""  
Formula:

      ---- a^(n/2) * a^(n/2)    (n is even number)
a^n = |
	  |
	  ---- a^((n-1)/2) * a^((n-1)/2) * a     (n is odd number)

"""

def equal(num1,num2):
	if (num1-num2) < 0.0000001 and (num1-num2) > -0.0000001:
		return True
	else:
		return False

def myPow_u(base,exponent):
	if exponent == 0:
		return 1
	if exponent == 1:
		return base
	result = myPow_u(base,exponent >> 1)
	result *= result
	if (exponent & 1) == 1:    # Odd number
		result *= base
	return result

def myPow(base,exponent):
	if equal(base,0.0):
		return 0
	expIsNeg = False
	if exponent < 0:
		exponent = -exponent
		expIsNeg = True
	result = myPow_u(base,exponent)
	if expIsNeg:
		result = 1 / result
	return result

str_ = input().split()
base,exp = float(str_[0]),int(str_[1])
print(myPow(base,exp))
