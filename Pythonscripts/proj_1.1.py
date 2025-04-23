'''
arr=[4,6,100]
n=len(arr)
sum=0
for i in range(n):
    sum=sum + arr[i]
print(sum)

str=[20,10,20,5,100]
n=len(str)
max=0
for i in range(n):
    if str[i]>max:
        max=str[i]
    else:
        max
print(max) '''

arr = [1, 2, 3, 8, 9, 5]
n=len(arr)
for i in range(n//2):
    temp=arr[i]
    arr[i]=arr[n-i-1]
    arr[n-i-1]=temp
print(arr)
