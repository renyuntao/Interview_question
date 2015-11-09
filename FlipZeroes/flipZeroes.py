#!/usr/bin/env python

# n is the size of arr
# m is maximum of number zeroes allowed to flip
def flipZeroes(arr,n,m):
	bestL,bestWindow = 0,0
	wL,wR = 0,0
	zeroCount = 0
	while wR < n:
		if zeroCount <= m:
			if arr[wR] == 0:
				zeroCount += 1
			wR += 1
		if zeroCount > m:
			if arr[wL] == 0:
				zeroCount -= 1
			wL += 1
		if wR - wL > bestWindow:
			bestWindow = wR - wL
			bestL = wL
	
	for i in range(bestWindow):
		if arr[bestL+i] == 0:
			print(bestL+i,end=' ')
	print()

arr = [1,0,0,1,1,0,1,0,1,1,1]
m = 2
n = len(arr)
flipZeroes(arr,n,m)
