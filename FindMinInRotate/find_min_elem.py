#!/usr/bin/env python

def findMin(arr,length):
	if length == 0:
		return
	ptr1 = 0
	ptr2 = length - 1
	middle = (ptr1+ptr2) // 2
	while ptr2 - ptr1 != 1:
		if arr[ptr1] == arr[middle] and arr[ptr1] == arr[ptr2]:
			minimum = arr[ptr1]
			for i in range(ptr1+1,ptr2+1):
				if minimum > arr[i]:
					minimum = arr[i]
			return minimum
		elif arr[middle] >= arr[ptr1]:
			ptr1 = middle
		elif arr[middle] < arr[ptr2]:
			ptr2 = middle
		middle = (ptr1+ptr2) // 2
	return arr[ptr2]

arr = [1,0,1,1,1]
#arr = [i for i in 'cdefghab']
print(findMin(arr,len(arr)))
