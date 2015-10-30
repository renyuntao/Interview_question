#!/usr/bin/env python

def equal(num1,num2):
	if (num1-num2) < 0.0000001 and (num1-num2) > -0.0000001:
		return True
	else:
		return False

def myPow(base,exponent):
	if equal(base,0.0):
		return 0.0
	expIsNeg = False
	if exponent < 0:
		expIsNeg = True
		exponent = -exponent
	res = 1.0
	for i in range(exponent):
		res *= base
	if expIsNeg:
		res = 1 / res
	return res

str_ = input().split()
base = float(str_[0])
exp = int(str_[1])
print(myPow(base,exp))
