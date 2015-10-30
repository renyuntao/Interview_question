#!/usr/bin/env python

def numOf1(num):
	count = 0
	while(num):
		num = num & (num-1)
		count += 1
	return count

print(numOf1(15))
