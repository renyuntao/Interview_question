#!/usr/bin/env python

def findMin(arr,length):
	if length == 0:
		return
	ptr1 = 0
	ptr2 = length - 1
	middle = (ptr1+ptr2) // 2
	while ptr2 - ptr1 != 1:
		if arr[middle] >= arr[ptr1]:
			ptr1 = middle
		elif arr[middle] < arr[ptr2]:
			ptr2 = middle
		middle = (ptr1+ptr2) // 2
	return arr[ptr2]

#arr = [3,4,5,1,2]
arr = [i for i in 'cdefghab']
print(findMin(arr,len(arr)))
