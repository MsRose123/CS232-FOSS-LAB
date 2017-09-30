print"DIVYA ROSE RAJU"
n=input("enter number of elements:")
l=[]
for i in range(n):
   l.append(input("enter element:"))
print l
print "sorted array is :"
for i in range(n):
  for j in range(n-1):
      if l[j]>=l[j+1] :
         temp=l[j]
         l[j]=l[j+1]
         l[j+1]=temp 
print l
